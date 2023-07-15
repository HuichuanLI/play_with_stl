#include <iostream>
#include  <utility>
//#include "stl_alloc.h"
#include "stl_vector.h"
//#include "stl_list.h"
//#include "stl_deque.h"
#include "stl_heap.h"
#include "stl_queue.h"
#include "stl_slist.h"
#include "stl_hashtable.h"
#include "stl_hash_set.h"
#include "stl_hashtable.h"
#include "stl_hash_map.h"

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


//
//int main() {
//    deque<int, alloc, 8> de;
//
//    de.push_front(1);
//    de.push_front(2);
//    de.push_front(3);
//    de.push_front(4);
//    de.push_front(5);
//    de.push_front(6);
//    de.push_front(7);
//    de.push_front(8);
//
//    de.push_back(10);
//    de.push_back(20);
//    de.push_back(30);
//
//    deque<int>::iterator it = de.begin();
//    while (it != de.end()) {
//        std::cout << *it << " ";
//        ++it;
//    }
//    std::cout << std::endl;
//}
//int main() {
////    list<int> mylist;
//
////    vector<int> iv(5);
////    iv.insert(iv.end(), 2, 10);
////
////    for (int i = 0; i < iv.size(); ++i)
////        std::cout << iv[i] << " ";
////    cout << endl;
//
////    iv.pop_back();
////    for (int i = 0; i < iv.size(); ++i)
////        std::cout << iv[i] << " ";
////    cout << endl;
//
////    iv.resize(5, 0); // 1 2 0 0 0
////    for (int i = 0; i < iv.size(); ++i)
////        cout << iv[i] << " ";
////    cout << endl;
////
////    std::cout << "capacity = " << iv.capacity() << std::endl;
////
////    iv.reserve(30);
//
////    std::cout << "capacity = " << iv.capacity() << std::endl;
//
//
//    list<int> slt(5, 3);
//
//    list<int>::iterator it = slt.begin();
//    while (it != slt.end()) {
//        std::cout << *it << "-->";
//        ++it;
//    }
//    std::cout << "Over." << std::endl;
//    return 0;
//}

#include <iostream>
//
//int main() {
//    int arr[] = {0, 1, 2, 3, 4, 8, 9, 3, 5,};
//    int n = 9;
//    vector<int> iv;
//    for (auto elem: arr)
//        iv.push_back(elem);
//
//    make_heap(iv.begin(), iv.end());
//    for (int i = 0; i < iv.size(); i++) {
//        std::cout << iv[i] << std::endl;
//    }
//    std::cout << std::endl;
//
//    iv.push_back(7);
//    push_heap(iv.begin(), iv.end());
//    for (int i = 0; i < iv.size(); i++) {
//        std::cout << iv[i] << std::endl;
//    }
//
//
////    pop_heap(iv.begin(), iv.end());
//
//    sort_heap(iv.begin(), iv.end());
//
//    for (int i = 0; i < iv.size(); i++) {
//        std::cout << iv[i] << std::endl;
//    }
//
//
//    //vector<int> iv(ar, ar+n);
//
//    int ar[10] = {0, 1, 2, 3, 4, 8, 90, 3, 5};
//
//    priority_queue<int> pq1(ar, ar + n);
//    std::cout << "size = " << pq1.size() << std::endl;
//    std::cout << "empty = " << pq1.empty() << std::endl;
//    std::cout << "top = " << pq1.top() << std::endl;
//    pq1.push(7);
//
//    pq1.pop();
//}

//int main() {
//    slist<int> slt(5, 3);
//
//    slist<int>::iterator it = slt.begin();
//    while (it != slt.end()) {
//        std::cout << *it << "-->";
//        ++it;
//    }
//    std::cout << "Over." << std::endl;
//}
struct Test {
    char a;
    double b;
    int c;

    bool operator==(const Test &t) {
        return c == t.c;
    }
};


struct MyGetKey {
    int operator()(const Test &t) const {
        return t.c;
    }
};


//int main() {
//    hashtable<int, int, bss::hash<int>, alloc> ht(7, bss::hash<int>());
//    ht.insert_equal(1);
//    ht.insert_equal(8);
//    ht.insert_equal(4);
//    ht.insert_equal(15);
//    ht.insert_equal(22);
//    ht.insert_equal(3);
//    ht.insert_equal(8);
//
//    hashtable<int, int, bss::hash<int>, alloc>::iterator it = ht.begin();
//    while (it != ht.end()) {
//        std::cout << *it << " ";
//        ++it;
//    }
//    std::cout << std::endl;
//}

//int main() {
//    hash_multiset<int> hs;
//
//    int ar[] = {10, 7, 8, 15, 5, 6, 8, 9, 7, 13, 12, 10, 11, 13, 12};
//    int n = sizeof(ar) / sizeof(ar[0]);
//
//    for (int i = 0; i < n; ++i)
//        hs.insert(ar[i]);
//
//    hash_multiset<int>::iterator it = hs.begin();
//    while (it != hs.end()) {
//        std::cout << *it << " ";
//        ++it;
//    }
//    std::cout << std::endl;
//}

//int main() {
//    hash_map<int, int> hm;
//
//    std::pair<const int, int> v[] = {{1, 100},
//                                     {3, 300},
//                                     {2, 200},
//                                     {4, 400}};
//    int n = sizeof(v) / sizeof(v[0]);
//
//    for (int i = 0; i < n; ++i)
//        hm.insert(v[i]);
//
//}

//int main() {
//    hash_multimap<int, int> hm;
//
//    std::pair<const int, int> v[] = {{1,  100},
//                                {30, 300},
//                                {2,  200},
//                                {4,  400},
//                                {1,  100},
//                                {30, 300},
//                                {2,  200},
//                                {4,  400}};
//    int n = sizeof(v) / sizeof(v[0]);
//
//    for (int i = 0; i < n; ++i)
//        hm.insert(v[i]);
//
//    hash_multimap<int, int>::iterator it = hm.begin();
//    while (it != hm.end()) {
//        std::cout << (*it).first << " : " << (*it).second << std::endl;
//        ++it;
//    }
//}

#include <numeric>
#include <set>
#include <fstream>

//int main() {
//    std::vector<int> iv = {1, 2, 3, 4, 5};
//    std::cout << std::accumulate(iv.begin(), iv.end(), 100) << std::endl;  //[  )
//    std::cout << accumulate(iv.begin(), iv.end(), 0, std::minus<int>()) << std::endl;  //[  )
//
//}

//int main() {
//    std::vector<int> iv = {1, 2, 30, 4, 5};
//    int res[5] = {0};
//    adjacent_difference(iv.begin(), iv.end(), res);
//}


//int main()
//{
//    std::vector<int> iv =  { 1, 2, 3, 4, 5 };
//
//    std::vector<int> iv1 = { 2, 2, 5 };
//
//    std::cout << inner_product(iv.begin(), iv.end(), iv1.begin(), 0) << std::endl;
//}

//int main() {
//    std::vector<int> iv = {1, 2, 3, 4, 5};
//    int res[5] = {0};
//
//    partial_sum(iv.begin(), iv.end(), res);
//    std::cout << pow(10, 5) << std::endl;
//
//}

//int main()
//{
//    std::vector<int> v1 = { 1, 3, 5, 7, 9 };
//    std::vector<int> v2 = { 2, 4, 6, 8, 10 };
//
//    std::vector<int> res(v1.size() + v2.size());
//
//    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
//}

//int main() {
//    std::multiset<int> s1 = {1, 1, 3, 5, 7, 9};
//    std::multiset<int> s2 = {1, 2, 4, 6, 8, 10};
//
//    std::vector<int> res(s1.size() + s2.size());
//    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
////    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(std::cout," "));
//}

//int main()
//{
//    std::vector<int> v = { 5, 8, 2, 4, 3, 1, 9, 7 };
//    //std::make_heap(v.begin(), v.end(), greater<int>());
//    std::make_heap(v.begin(), v.end());
//
//    v.push_back(16);
//    std::push_heap(v.begin(), v.end());
//
//    std::pop_heap(v.begin(), v.end());
//    v.pop_back();
//
//    std::sort_heap(v.begin(), v.end());
//}


/*
void main()
{
	std::multiset<int> v1 = { 1, 1, 1,3, 5, 7, 9 };
	std::multiset<int> v2 = { 1, 3, 4, 6, 8 };
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
}
*/

struct lessto5 {
    bool operator()(int &x) {
        return x < 5;
    }
};

//int main()
//{
//    std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
//    //cout<<count(v.begin(), v.end(), 3)<<endl;
//    //cout << count_if(v.begin(), v.end(), lessto5()) << endl;
//    std::cout << count_if(v.begin(), v.end(), bind2nd(std::less<int>(), 6)) << std::endl;
//}
//
//class even_by_two
//{
//public:
//    int operator()()const
//    {
//        return _x += 2;
//    }
//private:
//    static int _x;
//};
//int even_by_two::_x = 0;

class even_by_two {
public:
    int operator()() const {
        return _x += 2;
    }

private:
    static int _x;
};

int even_by_two::_x = 0;

struct display {
    void operator()(int &x) {
        std::cout << x << " ";
    }
};


//int main() {
//
//    std::vector<int> iv1(10);
//
//    //generate(iv1.begin(), iv1.end(), even_by_two());  //
//
//    generate_n(iv1.begin(), 5, even_by_two());
//
//    int ar[] = {0, 1, 4, 5, 6, 2, 3, 4, 5, 6, 6, 6, 7, 8};
//    int n = sizeof(ar) / sizeof(ar[0]);
//
//    std::for_each(ar, ar + n, display());
//
////    int ar[] = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
////    int n = sizeof(ar) / sizeof(ar[0]);
////    std::vector<int> iv1(ar, ar + n);
//
//    auto pos = remove(iv1.begin(), iv1.end(), 6);
//    //iv1.erase(pos, iv1.end());
//    remove_if(iv1.begin(), iv1.end(), bind2nd(std::less<int>(), 6));
//    std::vector<int> iv2(8);
//
//    remove_copy_if(iv1.begin(), iv1.end(), iv2.begin(), bind2nd(std::less<int>(), 6));
//
//    //replace(iv1.begin(), iv1.end(), 6, 3);
//    //replace_if(iv1.begin(), iv1.end(), bind2nd(less<int>(), 6), 9);
//    //replace_copy(iv1.begin(), iv1.end(), iv2.begin(), 6, 3);
//    replace_copy_if(iv1.begin(), iv1.end(), iv2.begin(), bind2nd(std::less<int>(), 6), 3);
//
//}

//template<class _Ty = void>
//struct plus
//{
//	//???????¡§??
//	result_type operator()(const first_argument_type& _Left, const second_argument_type& _Right) const
//	{
//		return (_Left + _Right);
//	}
//};


//int main() {
//    //plus<int> pl;
//
//    //pl(10,20) ==> pl.operator()(10,20)
//    std::cout << std::plus<int>()(10, 20) << std::endl;
//    std::vector<int> iv = {8, 5, 4, 6, 7, 6, 2, 1, 6, 9, 3};
//
//    sort(iv.begin(), iv.end(), std::less<int>());
//}

//int main() {
//    using namespace std;
//    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    for (int i = 0; i < iv.size(); ++i)
//        cout << iv[i] << " ";
//    cout << endl;
//
//    //std::vector<int>::iterator it = iv.begin();
//    auto it = iv.begin();
//    while (it != iv.end()) {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//
//    for (const int &e: iv)
//        cout << e << " ";
//    cout << endl;
//
//    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
//
////    ofstream ofile("MyTest.txt", ios::out);
////    copy(iv.begin(), iv.end(), ostream_iterator<int>(ofile, " "));
////    ofile.close();
//}

//int main() {
//    using namespace std;
//    ostream_iterator<int> outite(cout, " ");
//    deque<int> id = {0, 1, 2, 3, 4, 5};
//
//    copy(id.begin(), id.end(), outite);
//    cout << endl;
//
//    int ar[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
//
//    //20 30
//    copy(ar + 1, ar + 3, front_inserter(id)); //30, 20, 0, 1, 2, 3, 4, 5
//    copy(id.begin(), id.end(), outite);
//    cout << endl;
//
//    //50, 60
//    copy(ar + 4, ar + 6, back_inserter(id));//30, 20, 0, 1, 2, 3, 4, 5 50 60
//    copy(id.begin(), id.end(), outite);
//    cout << endl;
//
//    //10 20
//    auto ite = find(id.begin(), id.end(), 3);
//    copy(ar, ar + 2, inserter(id, ite)); //30, 20, 0, 1, 2, 10, 20, 3, 4, 5 50 60
//    copy(id.begin(), id.end(), outite);
//    cout << endl;
//}

class Shape {
public:
    virtual void display() = 0;
};

class Rect : public Shape {
public:
    virtual void display() {
        std::cout << "Rect ";
    }
};

class Circle : public Shape {
public:
    virtual void display() {
        std::cout << "Circle ";
    }
};

class Square : public Shape {
public:
    virtual void display() {
        std::cout << "Square ";
    }
};

int main() {
    using namespace std;
    std::vector<Shape *> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Square);
    v.push_back(new Circle);
    v.push_back(new Rect);

    for (int i = 0; i < v.size(); ++i)
        v[i]->display();
    cout << endl;

    for_each(v.begin(), v.end(), mem_fun(&Shape::display));
    cout << endl;
}
