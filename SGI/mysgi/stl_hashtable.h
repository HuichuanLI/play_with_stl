//
// Created by lhc456 on 2023/7/1.
//

#ifndef PLAY_WITH_ALGO_STL__HASHTABLE_H
#define PLAY_WITH_ALGO_STL__HASHTABLE_H

#include"stl_vector.h"
#include"stl_hash_fun.h"

template<class Value>
struct __hashtable_node {
    __hashtable_node *next;
    Value val;
};


static const int __stl_num_primes = 28 + 3;
static const unsigned long __stl_prime_list[__stl_num_primes] =
        {
                7, 13, 23, 53, 97, 193, 389, 769,
                1543, 3079, 6151, 12289, 24593,
                49157, 98317, 196613, 393241, 786433,
                1572869, 3145739, 6291469, 12582917, 25165843,
                50331653, 100663319, 201326611, 402653189, 805306457,
                1610612741, 3221225473ul, 4294967291ul
        };


unsigned long __stl_next_prime(unsigned long n) {
    const unsigned long *first = __stl_prime_list;
    const unsigned long *last = __stl_prime_list + __stl_num_primes;
    //const unsigned long* pos = lower_bound(first, last, n);
    for (; first != last; ++first) {
        if (*first >= n)
            break;
    }
    return first == last ? *(last - 1) : *first;
    //return pos == last ? *(last - 1) : *pos;
}

template<class Value, class Key, class HashFcn, class ExtractKey, class Alloc = alloc>
class hashtable;

template<class Value, class Key, class HashFcn, class ExtractKey, class Alloc>
class hashtable {
public:
    typedef size_t size_type;
    typedef Value value_type;
    typedef Key key_type;
    typedef __hashtable_node<Value> node;
    typedef HashFcn hasher;
    typedef simple_alloc<node, Alloc> node_allocator;
public:
    hashtable(size_type n, const HashFcn &hf)
            : hash(hf), get_key(ExtractKey()), num_elements(0) {
        initialize_buckets(n);
    }

private:
    size_type next_size(size_type n) const {
        return __stl_next_prime(n);
    }

    void initialize_buckets(size_type n) {
        const size_type n_buckets = next_size(n);
        buckets.reserve(n_buckets);
        buckets.insert(buckets.end(), n_buckets, (node *) 0);
        num_elements = 0;
    }

private:
    hasher hash;
    ExtractKey get_key;
    vector<node *, Alloc> buckets; //数组 桶
    size_type num_elements;
}

#endif //PLAY_WITH_ALGO_STL__HASHTABLE_H
