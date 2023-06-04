//
// Created by lhc456 on 2023/5/28.
//

#ifndef PLAY_WITH_ALGO_STL_VECTOR_H
#define PLAY_WITH_ALGO_STL_VECTOR_H
#pragma once

#include"stl_alloc.h"

template<class T, class Alloc=alloc>
class vector {
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef size_t size_type;
    typedef const value_type &const_reference;
public:
    typedef value_type *iterator;
public:
    vector() : start(0), finish(0), end_of_storage(0) {}

    vector(int n) {
        fill_initialize(n, T());
    }

private:
    void fill_initialize(size_type n, const T &value) {
        start = allocate_and_fill(n, value);
        finish = start + n;
        end_of_storage = finish;
    }

    iterator allocate_and_fill(size_type n, const T &x) {
        iterator result = data_allocator::allocate(n);
        return result;
    }

private:
    iterator start;
    iterator finish;
    iterator end_of_storage;
    typedef simple_alloc <value_type, Alloc> data_allocator;

}

#endif //PLAY_WITH_ALGO_STL_VECTOR_H
