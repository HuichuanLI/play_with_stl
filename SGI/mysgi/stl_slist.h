#pragma once

#include"stl_alloc.h"

struct __slist_node_base {
    __slist_node_base *next;
};
template<class T>
struct __slist_node : public __slist_node_base {
    T data;
};

__slist_node_base *__slist_make_link(__slist_node_base *prev_node,
                                     __slist_node_base *new_node) {
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return new_node;
}

//////////////////////////////////////////////////////////////////////////////

struct __slist_iterator_base {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef bss::forward_iterator_tag iterator_category;

    __slist_node_base *node;  //½ÚµãµÄÖ¸Õë

    __slist_iterator_base(__slist_node_base *x) : node(x) {}

    void incr() { node = node->next; }

    bool operator==(const __slist_iterator_base &x) const {
        return node == x.node;
    }

    bool operator!=(const __slist_iterator_base &x) const {
        return node != x.node;
    }
};

template<class T, class Ref, class Ptr>
struct __slist_iterator : public __slist_iterator_base {
    typedef __slist_iterator<T, Ref, Ptr> self;
    typedef __slist_node<T> list_node;
    typedef Ref reference;

    __slist_iterator(list_node *x) : __slist_iterator_base(x) {}

    __slist_iterator() : __slist_iterator_base(0) {}

    reference operator*() {
        return ((list_node *)  )->data;
    }

    self &operator++() {
        incr();
        return *this;
    }
};

template<class T, class Alloc = alloc>
class slist {
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
public:
    typedef struct __slist_iterator<T, T &, T *> iterator;
private:
    typedef __slist_node<T> list_node;
    typedef __slist_node_base list_node_base;
public:
    slist() {
        head.next = 0;
    }

    slist(size_type n, const value_type &x) {
        fill_initialize(n, x);
    }

public:
    iterator begin() {
        return iterator((list_node *) head.next);
    }

    iterator end() {
        return iterator(0);
    }

private:
    void fill_initialize(size_type n, const value_type &x) {
        head.next = 0;
        _insert_after_fill(&head, n, x);
    }

    void _insert_after_fill(list_node_base *pos, size_type n, const value_type &x) {
        for (size_type i = 0; i < n; ++i)
            pos = __slist_make_link(pos, create_node(x));
    }

    static list_node *create_node(const value_type &x) {
        list_node *node = list_node_allocator::allocate();  //malloc(sizeof(node))
        construct(&node->data, x);  //node->data = x;
        node->next = 0;             //node->next = 0;
        return node;
    }

protected:
    typedef simple_alloc<list_node, Alloc> list_node_allocator;
private:
    list_node_base head;
};