#pragma once

//使命：尽可能的分配成功
#include "stddef.h"
#include "stdlib.h"
//#define __USE_MALLOC

//一级空间配置器
template<int inst>
class __malloc_alloc_template {
public:
    static void *allocate(size_t n) {
        void *result = malloc(n);
        if (0 == result)
            return oom_malloc(n);  //out of memory 补救
        return result;
    }

    static void deallocate(void *p, size_t n) {
        free(p);
    }

    static void *reallocate(void *p, size_t old_sz, size_t new_sz) {
        void *result = realloc(p, new_sz);
        if (0 == result)
            return oom_realloc(p, new_sz);  //out of memory 补救
        return result;
    }

public:
    static void (*set_malloc_handler(void(*f)()))()  //函数
    {
        void (*old)() = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = f;
        return old;
    }

private:
    static void *oom_malloc(size_t n);

    static void *oom_realloc(void *p, size_t new_sz);

    static void (*__malloc_alloc_oom_handler)(); //函数指针
};

template<int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void *__malloc_alloc_template<inst>::oom_malloc(size_t n)  //new的实现
{
    void *result;
    void (*my_malloc_handler)();

    for (;;) {
        my_malloc_handler = __malloc_alloc_oom_handler;
        if (my_malloc_handler == 0)
            throw std::bad_alloc(); //抛出异常
        (*my_malloc_handler)();  //my_malloc_handler();
        result = malloc(n);
        if (result)
            return result;
    }
}

template<int inst>
void *__malloc_alloc_template<inst>::oom_realloc(void *p, size_t new_sz) {
    void *result;
    void (*my_malloc_handler)();

    for (;;) {
        my_malloc_handler = __malloc_alloc_oom_handler;
        if (my_malloc_handler == 0)
            throw std::bad_alloc(); //抛出异常
        (*my_malloc_handler)();  //my_malloc_handler();
        result = realloc(p, new_sz);
        if (result)
            return result;
    }
}

typedef __malloc_alloc_template<0> malloc_alloc;

/////////////////////////////////////////////////////////////////////////////////
//二级空间配置器

enum {
    __ALIGN = 8
};
enum {
    __MAX_BYTES = 128
};
enum {
    __NFREELISTS = __MAX_BYTES / __ALIGN
};

template<bool threads, int inst>
class __default_alloc_template {
public:
    static void *allocate(size_t n);

    static void deallocate(void *p, size_t n);

    static void *reallocate(void *p, size_t old_sz, size_t new_sz);

private:
    union obj {
        union obj *free_list_link;
        char client_data[1];
    };
private:
    static size_t ROUND_UP(size_t bytes) {
        return (bytes + __ALIGN - 1) & ~(__ALIGN - 1);
    }

    static size_t FREELIST_INDEX(size_t bytes) {
        return (bytes + __ALIGN - 1) / __ALIGN - 1;
    }

private:
    static void *refill(size_t n);

    static char *chunk_alloc(size_t size, int &objs);  //objs是引用传递
private:
    static obj *free_list[__NFREELISTS];
private:
    static char *start_free;
    static char *end_free;
    static size_t heap_size;
};

template<bool threads, int inst>
char *__default_alloc_template<threads, inst>::start_free = 0;
template<bool threads, int inst>
char *__default_alloc_template<threads, inst>::end_free = 0;
template<bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;

template<bool threads, int inst>
typename __default_alloc_template<threads, inst>::obj *
        __default_alloc_template<threads, inst>::free_list[__NFREELISTS] =
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template<bool threads, int inst>
void *__default_alloc_template<threads, inst>::allocate(size_t n) {
    obj **my_free_list;
    obj *result;

    if (n > __MAX_BYTES)
        return malloc_alloc::allocate(n);

    my_free_list = free_list + FREELIST_INDEX(n);
    result = *my_free_list;
    if (result == 0) {
        void *r = refill(ROUND_UP(n));
        return r;
    }

    *my_free_list = result->free_list_link;
    return result;
}

template<bool threads, int inst>
void *__default_alloc_template<threads, inst>::refill(size_t n) //块
{
    int nobjs = 20;//经验值
    char *chunk = chunk_alloc(n, nobjs);

    if (nobjs == 1)
        return chunk;

    obj **my_free_list;
    obj *result;
    obj *current_obj, *next_obj;

    my_free_list = free_list + FREELIST_INDEX(n);
    result = (obj *) chunk;
    *my_free_list = next_obj = (obj *) (chunk + n);

    for (int i = 1;; i++) {
        current_obj = next_obj;
        next_obj = (obj *) ((char *) next_obj + n);
        if (nobjs - 1 == i) {
            current_obj->free_list_link = 0;
            break;
        } else
            current_obj->free_list_link = next_obj;
    }
    return result;
}

template<bool threads, int inst>
char *__default_alloc_template<threads, inst>::chunk_alloc(size_t size, int &nobjs) {
    char *result;
    size_t total_bytes = size * nobjs;
    size_t bytes_left = end_free - start_free;

    if (bytes_left >= total_bytes) {
        result = start_free;
        start_free += total_bytes;
        return result;
    } else if (bytes_left >= size) {
        nobjs = bytes_left / size;
        total_bytes = size * nobjs;
        result = start_free;
        start_free += total_bytes;
        return result;
    } else {
        size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);

        if (bytes_left > 0) {
            obj **my_free_list = free_list + FREELIST_INDEX(bytes_left);
            ((obj *) start_free)->free_list_link = *my_free_list;
            *my_free_list = (obj *) start_free;
        }

        start_free = (char *) malloc(bytes_to_get);
        if (start_free == 0) {
            obj **my_free_list;
            obj *p;
            for (int i = size; i <= __MAX_BYTES; i += __ALIGN) {
                my_free_list = free_list + FREELIST_INDEX(i);
                p = *my_free_list;
                if (p != 0) {
                    *my_free_list = p->free_list_link;
                    start_free = (char *) p;
                    end_free = start_free + i;
                    return chunk_alloc(size, nobjs);
                }
            }
            end_free = 0;
            start_free = (char *) malloc_alloc::allocate(bytes_to_get);
        }

        heap_size += bytes_to_get;
        end_free = start_free + bytes_to_get;

        return chunk_alloc(size, nobjs); //递归调动
    }

    return result;
}


template<bool threads, int inst>
void __default_alloc_template<threads, inst>::deallocate(void *p, size_t n) {
    if (n > __MAX_BYTES) {
        malloc_alloc::deallocate(p, n);
        return;
    }

    obj **my_free_list = free_list + FREELIST_INDEX(n);
    obj *q = (obj *) p;
    q->free_list_link = *my_free_list;  //q->next = phead;
    *my_free_list = q;                  //phead = q;
}

template<bool threads, int inst>
void *__default_alloc_template<threads, inst>::reallocate(void *p, size_t old_sz, size_t new_sz) {
    void *result;
    size_t copy_sz;

    if (old_sz > (size_t) __MAX_BYTES && new_sz > (size_t) __MAX_BYTES) {
        return (realloc(p, new_sz));
    }
    if (ROUND_UP(old_sz) == ROUND_UP(new_sz))
        return (p);

    //申请空间
    result = allocate(new_sz);
    copy_sz = new_sz > old_sz ? old_sz : new_sz;
    memcpy(result, p, copy_sz);

    //释放空间
    deallocate(p, old_sz);
    return (result);
}


////////////////////////////////////////////////////////////////////////////
//分装空间配置器
#ifdef __USE_MALLOC
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<0, 0> alloc;
#endif

template<class T, class Alloc>
class simple_alloc {
public:
    static T *allocate(size_t n) //数组空间
    {
        return 0 == n ? 0 : (T *) Alloc::allocate(n * sizeof(T));
    }

    static T *allocate() //单个数据空间
    {
        return (T *) Alloc::allocate(sizeof(T));
    }

    static void deallocate(T *p, size_t n) //释放数组空间
    {
        if (0 != n)
            Alloc::deallocate(p, n * sizeof(T));
    }

    static void deallocate(T *p) //释放单个数据空间
    {
        Alloc::deallocate(p, sizeof(T));
    }
};