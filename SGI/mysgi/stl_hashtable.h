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
struct __hashtable_iterator {
    typedef __hashtable_node<Value> node;
    typedef hashtable<Value, Key, HashFcn, ExtractKey, Alloc> hashtable;
    typedef __hashtable_iterator<Value, Key, HashFcn, ExtractKey, Alloc> iterator;
    typedef Value &reference;
    typedef __hashtable_iterator<Value, Key, HashFcn, ExtractKey, Alloc> self;
    typedef size_t size_type;

    __hashtable_iterator(node *n, hashtable *tab) : cur(n), ht(tab) {}

    __hashtable_iterator() {}

    self &operator++() {
        const node *old = cur;
        cur = cur->next;
        if (!cur) {
            size_type bucket = ht->bkt_num(old->val);
            while (!cur && ++bucket < ht->buckets.size())
                cur = ht->buckets[bucket];
        }
        return *this;
    }

    reference operator*() {
        return cur->val;
    }

    bool operator!=(const iterator &x) {
        return cur != x.cur;
    }

    node *cur;
    hashtable *ht;
};

template<class Value, class Key, class HashFcn, class ExtractKey, class Alloc>
class hashtable {
    friend struct __hashtable_iterator<Value, Key, HashFcn, ExtractKey, Alloc>;

public:
    typedef size_t size_type;
    typedef Value value_type;
    typedef Key key_type;
    typedef __hashtable_node<Value> node;
    typedef HashFcn hasher;
    typedef simple_alloc<node, Alloc> node_allocator;
    typedef __hashtable_iterator<Value, Key, HashFcn, ExtractKey, Alloc> iterator;
public:
    iterator begin() {
        for (size_type n = 0; n < buckets.size(); ++n) {
            if (buckets[n])
                return iterator(buckets[n], this);
        }
        return end();
    }

    iterator end() {
        return iterator(0, this);
    }

public:
    hashtable(size_type n, const HashFcn &hf)
            : hash(hf), get_key(ExtractKey()), num_elements(0) {
        initialize_buckets(n);
    }

    void resize(size_type num_elements_hint) {
        const size_type old_n = buckets.size();
        if (num_elements_hint > old_n) {
            const size_type n = next_size(num_elements_hint);
            if (n > old_n) {
                vector<node *, Alloc> tmp(n, (node *) 0);

                for (size_type bucket = 0; bucket < old_n; ++bucket) {
                    node *first = buckets[bucket];
                    while (first) {
                        size_type new_bucket = bkt_num(first->val, n);
                        buckets[bucket] = first->next;
                        first->next = tmp[new_bucket];
                        tmp[new_bucket] = first;
                        first = buckets[bucket];
                    }
                }
                buckets.swap(tmp);

            }
        }
    }

    void insert_unique(const value_type &obj) {
        resize(num_elements + 1);
        insert_unique_noresize(obj);
    }

    void insert_equal(const value_type &obj) {
        resize(num_elements + 1);
        insert_equal_noresize(obj);
    }

    void insert_equal_noresize(const value_type &obj) {
        const size_type n = bkt_num(obj);
        node *first = buckets[n];

        for (node *cur = first; cur; cur = cur->next) {
            //if (equals(get_key(cur->val), get_key(obj)))
            if (cur->val == obj) {
                node *tmp = new_node(obj);
                tmp->next = cur->next;
                cur->next = tmp;
                ++num_elements;
                //return iterator(tmp, this);
                return;
            }
        }
        node *tmp = new_node(obj);  //Ö±½ÓÍ·²å
        tmp->next = first;
        buckets[n] = tmp;
        ++num_elements;
        //return iterator(tmp, this); //ÔÝÇÒ²»·µ»Ø
    }

    void insert_unique_noresize(const value_type &obj) {
        const size_type n = bkt_num(obj);
        node *first = buckets[n];

        for (node *cur = first; cur; cur = cur->next) {
            //if (equals(get_key(cur->val), get_key(obj)))
            if (cur->val == obj)
                //return pair<iterator, bool>(iterator(cur, this), false);
                return;
        }

        node *tmp = new_node(obj);
        tmp->next = first;
        buckets[n] = tmp;
        ++num_elements;
        //return pair<iterator, bool>(iterator(tmp, this), true);
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

    size_type bkt_num_key(const key_type &key) const {
        return bkt_num_key(key, buckets.size());
    }

    size_type bkt_num(const value_type &obj) const {
//        return bkt_num_key(get_key(obj));
        return bkt_num_key(obj);
    }

    size_type bkt_num_key(const key_type &key, size_t n) const {
        return hash(key) % n;
    }

    size_type bkt_num(const value_type &obj, size_t n) const {
        return bkt_num_key(obj, n);
    }

    node *new_node(const value_type &obj) {
        node *n = node_allocator::allocate();
        n->next = 0;
        construct(&n->val, obj);
        return n;
    }

private:
    hasher hash;
    ExtractKey get_key;
    vector<node *, Alloc> buckets; //数组 桶
    size_type num_elements;
};

#endif //PLAY_WITH_ALGO_STL__HASHTABLE_H
