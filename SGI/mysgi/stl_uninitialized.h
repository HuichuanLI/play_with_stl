//
// Created by lhc456 on 2023/5/29.
//

#ifndef PLAY_WITH_ALGO_STL_UNINITIALIZED_H
#define PLAY_WITH_ALGO_STL_UNINITIALIZED_H
#pragma once

#include"stl_iterator.h"
#include"type_traits.h"
#include"stl_construct.h"
#include"stl_algobase.h"

namespace bss {
    //uninitialized_copy

    template<class InputIterator, class ForwardIterator>
    ForwardIterator
    __uninitialized_copy_aux(InputIterator first, InputIterator last, ForwardIterator result, __true_type) {
        return copy(first, last, result);
    }

    template<class InputIterator, class ForwardIterator>
    ForwardIterator
    __uninitialized_copy_aux(InputIterator first, InputIterator last, ForwardIterator result, __false_type) {
        ForwardIterator cur = result;
        for (; first != last; ++first, ++cur)
            construct(&*cur, *first);
        return cur;

    }

    template<class InputIterator, class ForwardIterator, class T>
    ForwardIterator __uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result, T *) {
        typedef typename __type_traits<T>::is_POD_type is_POD;
        return __uninitialized_copy_aux(first, last, result, is_POD());
    }

    template<class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result) {
        return __uninitialized_copy(first, last, result, value_type(result));
    }

    //uninitialized_fill_n
    template<class ForwardIterator, class Size, class T>
    ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first, Size n, const T &x, __true_type) {
        return bss::fill_n(first, n, x);
    }

    template<class ForwardIterator, class Size, class T>
    ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first, Size n, const T &x, __false_type) {
        ForwardIterator cur = first;
        for (; n > 0; --n, ++cur)
            construct(&*cur, x);
        return cur;
    }

    template<class ForwardIterator, class Size, class T, class T1>
    ForwardIterator __uninitialized_fill_n(ForwardIterator first, Size n, const T &x, T1 *) {
        typedef typename __type_traits<T1>::is_POD_type is_POD;   //is pod ?

        //cout<<"is_POD = "<<typeid(is_POD).name()<<endl;

        return __uninitialized_fill_n_aux(first, n, x, is_POD()); //__false_type()
    }

    template<class ForwardIterator, class Size, class T>
    ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T &x) {
        return __uninitialized_fill_n(first, n, x, value_type(first)); //��ȡ����
    }
}
#endif //PLAY_WITH_ALGO_STL_UNINITIALIZED_H
