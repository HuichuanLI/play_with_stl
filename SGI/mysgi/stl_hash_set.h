#pragma once

#include"stl_hashtable.h"

template<class Value, class HashFcn = bss::hash<Value>, class Alloc = alloc>
class hash_set {
private:
    typedef hashtable<Value, Value, HashFcn, Alloc> ht;
    ht rep;
public:
    typedef Value value_type;
    typedef HashFcn hasher;
    typedef typename ht::iterator iterator;
public:
    hash_set() : rep(7, hasher()) {}

public:
    iterator begin() {
        return rep.begin();
    }

    iterator end() {
        return rep.end();
    }

public:
    void insert(const value_type &x) {
        rep.insert_unique(x);
    }
};


template<class Value, class HashFcn = hash <Value>, class Alloc = alloc>
class hash_multiset {
private:
    typedef hashtable<Value, Value, HashFcn, Alloc> ht;
    ht rep;
public:
    typedef Value value_type;
    typedef HashFcn hasher;
    typedef typename ht::iterator iterator;
public:
    hash_multiset() : rep(7, hasher()) {}

public:
public:
    iterator begin() {
        return rep.begin();
    }

    iterator end() {
        return rep.end();
    }

public:
    void insert(const value_type &x) {
        rep.insert_equal(x);
    }
};