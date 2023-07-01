//
// Created by lhc456 on 2023/6/12.
//

#ifndef PLAY_WITH_ALGO_STL_QUEUE_H
#define PLAY_WITH_ALGO_STL_QUEUE_H
#pragma once

#include"stl_vector.h"
#include"stl_deque.h"
#include"stl_heap.h"
#include <functional>


template<class T, class Sequence = deque<T> >
class queue {
    friend bool operator==(const queue &x, const queue &y);

    friend bool operator<(const queue &x, const queue &y);

public:
    typedef typename Sequence::value_type value_type;
    typedef typename Sequence::size_type size_type;
    typedef typename Sequence::reference reference;
    typedef typename Sequence::const_reference const_reference;
protected:
    Sequence c;
public:
    bool empty() const { return c.empty(); }

    size_type size() const { return c.size(); }

    reference front() { return c.front(); }

    const_reference front() const { return c.front(); }

    reference back() { return c.back(); }

    const_reference back() const { return c.back(); }

    void push(const value_type &x) { c.push_back(x); }

    void pop() { c.pop_front(); }
};

template<class T, class Sequence>
bool operator==(const queue<T, Sequence> &x, const queue<T, Sequence> &y) {
    return x.c == y.c;
}

template<class T, class Sequence>
bool operator<(const queue<T, Sequence> &x, const queue<T, Sequence> &y) {
    return x.c < y.c;
}


//priority_queue
template<class T, class Sequence = vector<T>, class Compare = std::less<typename Sequence::value_type> >
class priority_queue {
public:
    typedef typename Sequence::value_type value_type;
    typedef typename Sequence::size_type size_type;
    typedef typename Sequence::reference reference;
    typedef typename Sequence::const_reference const_reference;
public:
    priority_queue() : c() {}

    priority_queue(const Compare &x) : c(), comp(x) {}

     priority_queue(value_type *first, value_type *last) : c(first, last) {
        make_heap(c.begin(), c.end());
    }

public:
    bool empty() const { return c.empty(); }

    size_type size() const { return c.size(); }

    const_reference top() const { return c.front(); }

    void push(const value_type &x) {
        c.push_back(x);
        push_heap(c.begin(), c.end());
    }

    void pop() {
        pop_heap(c.begin(), c.end());
        c.pop_back();
    }

protected:
    Sequence c;
    Compare comp;
};

#endif //PLAY_WITH_ALGO_STL_QUEUE_H
