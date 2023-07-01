//
// Created by lhc456 on 2023/6/13.
//

#ifndef PLAY_WITH_ALGO_STL_HEAP_H
#define PLAY_WITH_ALGO_STL_HEAP_H
#pragma once

#include"stl_iterator.h"

template<class RandomAccessIterator, class Distance, class T>
void __push_heap(RandomAccessIterator first, Distance holeIndex,
                 Distance topIndex, T value) {
    Distance parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && *(first + parent) < value) {
        *(first + holeIndex) = *(first + parent);
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = value;
}

template<class RandomAccessIterator, class Distance, class T>
void __push_heap_aux(RandomAccessIterator first,
                     RandomAccessIterator last, Distance *, T *) {
    __push_heap(first, Distance((last - first) - 1), Distance(0), T(*(last - 1)));
}

template<class RandomAccessIterator>
void push_heap(RandomAccessIterator first, RandomAccessIterator last) {
    __push_heap_aux(first, last, bss::distance_type(first), bss::value_type(first));
}


//pop_heap

template<class RandomAccessIterator, class Distance, class T>
void __adjust_heap(RandomAccessIterator first, Distance holeIndex,
                   Distance len, T value) {
    Distance topIndex = holeIndex;
    Distance secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (*(first + secondChild) < *(first + (secondChild - 1)))
            secondChild--;
        *(first + holeIndex) = *(first + secondChild);
        holeIndex = secondChild;
        secondChild = 2 * (secondChild + 1);
    }
    if (secondChild == len) {
        *(first + holeIndex) = *(first + (secondChild - 1));
        holeIndex = secondChild - 1;
    }
    __push_heap(first, holeIndex, topIndex, value);
}

template<class RandomAccessIterator, class T, class Distance>
void __pop_heap(RandomAccessIterator first, RandomAccessIterator last,
                RandomAccessIterator result, T value, Distance *) {
    *result = *first;
    __adjust_heap(first, Distance(0), Distance(last - first), value);
}

template<class RandomAccessIterator, class T>
void __pop_heap_aux(RandomAccessIterator first,
                    RandomAccessIterator last, T *) {
    __pop_heap(first, last - 1, last - 1, T(*(last - 1)), bss::distance_type(first));
}

template<class RandomAccessIterator>
void pop_heap(RandomAccessIterator first, RandomAccessIterator last) {
    __pop_heap_aux(first, last, bss::value_type(first));
}

//make_heap
template<class RandomAccessIterator, class T, class Distance>
void __make_heap(RandomAccessIterator first, RandomAccessIterator last, T *, Distance *) {
    if (last - first < 2)
        return;
    Distance len = last - first;
    Distance parent = (len - 2) / 2;

    while (true) {
        __adjust_heap(first, parent, len, T(*(first + parent)));
        if (parent == 0)
            return;
        parent--;
    }
}

template<class RandomAccessIterator>
void make_heap(RandomAccessIterator first, RandomAccessIterator last) {
    __make_heap(first, last, bss::value_type(first), bss::distance_type(first));
}

//sort_heap
template<class RandomAccessIterator>
void sort_heap(RandomAccessIterator first, RandomAccessIterator last) {
    while (last - first > 1)
        pop_heap(first, last--);
}

#endif //PLAY_WITH_ALGO_STL_HEAP_H
