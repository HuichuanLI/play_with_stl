#include <iostream>
#include <list>
#include "stl_alloc.h"

using namespace std;

namespace my_stl {

    template<class T>
    T *_allocate(size_t size, T *) {
        set_new_handler(0);
        T *tmp = (T *) ::operator new(size * sizeof(T));  //malloc
        if (tmp == 0) {
            cerr << "out of memory." << endl;
            exit(1);
        }
        return tmp;
    }

    template<class T>
    void _deallocate(T *buffer)  //free
    {
        ::operator delete(buffer);
    }

    template<class T1, class T2>
    void _construct(T1 *p, const T2 &value)  //¶¨Î»new placement new
    {
        new(p) T1(value);
    }

    template<class T>
    void _destroy(T *ptr) {
        ptr->~T();
    }


    template<class T>
    class allocator {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;
    public:
        pointer allocate(size_type n, const void *hint = 0) {
            return _allocate(n, (pointer) 0);
        }

        void deallocate(pointer p, size_type n) {
            _deallocate(p);
        }

        void construct(pointer p, const T &value) {
            _construct(p, value);
        }

        void destroy(pointer p) {
            _destroy(p);
        }
    };

}

void Out_Of_Memory() {
    cout << "Out Of Memory." << endl; //free ?????????????¡Â
    exit(1);
}

int main() {
    //set_new_handler();

    int n = 1;
    int *ptr = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int));
    int *ptr1 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int));  //8

    int *ptr2 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int) * 25); //100

    int *ptr3 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int) * 16); //64

    int *ptr4 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int) * 14);

    return 0;
}