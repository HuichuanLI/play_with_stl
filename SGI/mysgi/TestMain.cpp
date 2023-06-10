#include <iostream>
#include <list>
#include "stl_alloc.h"
#include "stl_vector.h"
#include "stl_list.h"

//using namespace std;
//
//namespace my_stl {
//
//    template<class T>
//    T *_allocate(size_t size, T *) {
//        set_new_handler(0);
//        T *tmp = (T *) ::operator new(size * sizeof(T));  //malloc
//        if (tmp == 0) {
//            cerr << "out of memory." << endl;
//            exit(1);
//        }
//        return tmp;
//    }
//
//    template<class T>
//    void _deallocate(T *buffer)  //free
//    {
//        ::operator delete(buffer);
//    }
//
//    template<class T1, class T2>
//    void _construct(T1 *p, const T2 &value)  //¶¨Î»new placement new
//    {
//        new(p) T1(value);
//    }
//
//    template<class T>
//    void _destroy(T *ptr) {
//        ptr->~T();
//    }
//
//
//    template<class T>
//    class allocator {
//    public:
//        typedef T value_type;
//        typedef T *pointer;
//        typedef const T *const_pointer;
//        typedef T &reference;
//        typedef const T &const_reference;
//        typedef size_t size_type;
//    public:
//        pointer allocate(size_type n, const void *hint = 0) {
//            return _allocate(n, (pointer) 0);
//        }
//
//        void deallocate(pointer p, size_type n) {
//            _deallocate(p);
//        }
//
//        void construct(pointer p, const T &value) {
//            _construct(p, value);
//        }
//
//        void destroy(pointer p) {
//            _destroy(p);
//        }
//    };
//
//}

void Out_Of_Memory() {
    std::cout << "Out Of Memory." << std::endl; //free ?????????????¡Â
    exit(1);
}

//int main() {
//    //set_new_handler();
//
//    int n = 1;
//    int *ptr = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int));
//    int *ptr1 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int));  //8
//
//    int *ptr2 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int) * 25); //100
//
//    int *ptr3 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int) * 16); //64
//
//    int *ptr4 = (int *) __default_alloc_template<0, 0>::allocate(sizeof(int) * 14);
//
//    return 0;
//}


//class Test {
//public:
//    Test(int d = 0) : m_data(d) {}
//
//private:
//    int m_data;
//};
//
//
//int main() {
//    vector<Test> iv(5);// 0 0 0 0 0
//    return 0;
//}

#define N 10

class CIntArray {
public:
    CIntArray() {
        for (int i = 0; i < N; ++i)
            ar[i] = i + 1; //1 2 3 4 5 6 7 8 9 10
    }

    int GetSum(int times) {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += ar[i];
        return sum * times;
    }

private:
    int ar[N];
};

class CFloatArray {
public:
    CFloatArray() {
        for (int i = 0; i < N; ++i)
            ar[i] = i + 1.11;
    }

    float GetSum(float times) {
        float sum = 0;
        for (int i = 0; i < N; ++i)
            sum += ar[i];
        return sum * times;
    }

private:
    float ar[N];
};

template<class T>
struct type_traits {
};

template<>
struct type_traits<CIntArray> {
    typedef int return_type;
    typedef int arg_type;
};

template<>
struct type_traits<CFloatArray> {
    typedef float return_type;
    typedef float arg_type;
};

template<class T>
class CApply {
public:
    typename type_traits<T>::return_type GetSum(T &obj, typename type_traits<T>::arg_type times)  //?????¡ì¡À?
    {
        //cout << typeid(type_traits<T>::arg_type).name()<<endl;
        //cout << typeid(type_traits<T>::return_type).name() << endl;

        return obj.GetSum(times);
    }
};

//int main() {
//    CIntArray cint;
//    CFloatArray cfloat;
//
//    //cout<<cint.GetSum(2)<<endl;
//    //cout<<cfloat.GetSum(2.2)<<endl;
//
//    CApply<CIntArray> c1;
//    CApply<CFloatArray> c2;
//
//    std::cout << c1.GetSum(cint, 2) << std::endl;
//    std::cout << c2.GetSum(cfloat, 2.2) << std::endl;
//
//    return 0;
//}


int main() {
    list<int> mylist;

//    vector<int> iv(5);
//    iv.insert(iv.end(), 2, 10);
//
//    for (int i = 0; i < iv.size(); ++i)
//        std::cout << iv[i] << " ";
//    cout << endl;

//    iv.pop_back();
//    for (int i = 0; i < iv.size(); ++i)
//        std::cout << iv[i] << " ";
//    cout << endl;

//    iv.resize(5, 0); // 1 2 0 0 0
//    for (int i = 0; i < iv.size(); ++i)
//        cout << iv[i] << " ";
//    cout << endl;
//
//    std::cout << "capacity = " << iv.capacity() << std::endl;
//
//    iv.reserve(30);

//    std::cout << "capacity = " << iv.capacity() << std::endl;
    return 0;
}