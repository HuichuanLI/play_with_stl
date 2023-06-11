//
// Created by lhc456 on 2023/6/12.
//

#ifndef PLAY_WITH_ALGO_STL_STACK_H
#define PLAY_WITH_ALGO_STL_STACK_H
#pragma once

#include"stl_deque.h"

using namespace std;

template<class T, class Sequence = deque<T> >
class stack {
    friend bool operator==(const stack &, const stack &);

    friend bool operator<(const stack &, const stack &);

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

    reference top() { return c.back(); }

    const_reference top() const { return c.back(); }

    void push(const value_type &x) { c.push_back(x); }

    void pop() { c.pop_back(); }
};

template<class T, class Sequence>
bool operator==(const stack<T, Sequence> &x, const stack<T, Sequence> &y) {
    return x.c == y.c;
}

template<class T, class Sequence>
bool operator<(const stack<T, Sequence> &x, const stack<T, Sequence> &y) {
    return x.c < y.c;
}

#endif //PLAY_WITH_ALGO_STL_STACK_H
