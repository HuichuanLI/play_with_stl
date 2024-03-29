#pragma once

#include"stl_iterator.h"

//construct
template<class T1, class T2>
void construct(T1 *p, const T2 &value) {
    new(p)T1(value);  //placement new
}

template<class T>
void destroy(T *pointer) {
    pointer->~T();
}

//destroy
template<class ForwardIterator>
void __destroy_aux(ForwardIterator first, ForwardIterator last, __false_type) {
    for (; first < last; ++first)
        destroy(&*first);
}

template<class ForwardIterator>
void __destroy_aux(ForwardIterator, ForwardIterator, __true_type) {}

template<class ForwardIterator, class T>
void __destroy(ForwardIterator first, ForwardIterator last, T *) {
    typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
    __destroy_aux(first, last, trivial_destructor());
}

template<class ForwardIterator>
void destroy(ForwardIterator first, ForwardIterator last) {
    __destroy(first, last, bss::value_type(first));
}