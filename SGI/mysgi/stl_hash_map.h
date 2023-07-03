#pragma once

#include"stl_hashtable.h"
#include"stl_function.h"
#include  <utility>


template<class Key, class T, class HashFcn = bss::hash<Key>, class Alloc = alloc>
class hash_map {
private:
    typedef hashtable<std::pair<const Key, T>, Key, HashFcn,
            select1st<std::pair<const Key, T>>, Alloc> ht;
    ht rep;
public:
    typedef typename ht::value_type value_type;  //pair<Key, T>
    typedef HashFcn hasher;
    typedef typename ht::iterator iterator;
public:
    hash_map() : rep(7, hasher()) {}

public:
    void insert(const value_type &obj) {
        rep.insert_unique(obj);
    }

public:
    iterator begin() { return rep.begin(); }

    iterator end() { return rep.end(); }
};


template<class Key, class T, class HashFcn = bss::hash<Key>, class Alloc = alloc>
class hash_multimap {
private:
    typedef hashtable<pair<const Key, T>, Key, HashFcn,
            select1st<pair<const Key, T>>, Alloc> ht;
    ht rep;
public:
    typedef typename ht::value_type value_type;  //pair<Key, T>
    typedef HashFcn hasher;
    typedef typename ht::iterator iterator;
public:
    hash_multimap() : rep(7, hasher()) {}

public:
    void insert(const value_type &obj) {
        rep.insert_equal(obj);
    }

public:
    iterator begin() {
        return rep.begin();
    }

    iterator end() {
        return rep.end();
    }
};