//
// Created by lhc456 on 2023/5/28.
//

#ifndef PLAY_WITH_ALGO_STL_VECTOR_H
#define PLAY_WITH_ALGO_STL_VECTOR_H
#pragma once

#pragma once

#include"stl_alloc.h"
#include"stl_uninitialized.h"

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

    vector(int n, const T &value) {
        fill_initialize(n, value);
    }

    vector(iterator first, iterator last) {
        size_type n = 0;
        bss::distance(first, last, n);
        start = allocate_and_copy(n, first, last);
        finish = start + n;
        end_of_storage = finish;
    }

    ~vector() {
        destroy(start, finish);
        deallocate();
    }

public:
    iterator begin() {
        return start;
    }

    iterator end() {
        return finish;
    }

    iterator begin() const {
        return start;
    }

    iterator end() const {
        return finish;
    }

    size_type size() const {
        return (size_type) (end() - begin());
    }

    size_type capacity() const {
        return (size_type) (end_of_storage - begin());
    }

    bool empty() const {
        return end() == begin();
    }

    reference operator[](size_type n) {
        return *(begin() + n);  // *(p+i);
    }

    reference front() {
        return *begin();
    }

    const_reference front() const {
        return *begin();
    }

    reference back() {
        return *(end() - 1);
    }

public:
    void push_back(const T &x)  //insert(end(), 1, x);
    {
        if (finish != end_of_storage) {
            construct(finish, x);
            ++finish;
        } else {
            insert_aux(end(), x);
        }
    }

    void pop_back() {
        --finish;
        destroy(finish);
    }

    void insert_aux(iterator position, const T &x);

    void insert(iterator position, size_type n, const T &x);

    iterator erase(iterator first, iterator last) {
        iterator i = copy(last, finish, first);
        destroy(i, finish);
        finish = finish - (last - first);
        return first;
    }

    iterator erase(iterator position) {
        if (position + 1 != end())
            bss::copy(position + 1, finish, position);
        --finish;
        destroy(finish);
        return position;
    }

    void resize(size_type new_size, const T &x) {
        if (new_size < size())
            erase(begin() + new_size, end());
        else
            insert(end(), new_size - size(), x);
    }

    void reserve(size_type n) {
        if (capacity() < n) {
            const size_type old_size = size();
            iterator tmp = allocate_and_copy(n, start, finish);
            destroy(start, finish);
            deallocate();
            start = tmp;
            finish = tmp + old_size;
            end_of_storage = start + n;
        }
    }

    void clear() {
        erase(begin(), end());
    }

    void swap(vector<T, Alloc> &x) {
        std::swap(start, x.start);
        std::swap(finish, x.finish);
        std::swap(end_of_storage, x.end_of_storage);
    }

private:
    void fill_initialize(size_type n, const T &value) {
        start = allocate_and_fill(n, value);
        finish = start + n;
        end_of_storage = finish;
    }

    iterator allocate_and_fill(size_type n, const T &x) {
        iterator result = data_allocator::allocate(n);
        bss::uninitialized_fill_n(result, n, x);
        return result;
    }

    iterator allocate_and_copy(size_type n, iterator first, iterator last) {
        iterator result = data_allocator::allocate(n);
        bss::uninitialized_copy(first, last, result);
        return result;
    }

    void deallocate() {
        if (start)
            data_allocator::deallocate(start, end_of_storage - start);
    }

private:
    iterator start;
    iterator finish;
    iterator end_of_storage;
    typedef simple_alloc<value_type, Alloc> data_allocator;
};


template<class T, class Alloc>
void vector<T, Alloc>::insert(iterator position, size_type n, const T &x) {
    if (n != 0) {
        if ((size_type) (end_of_storage - finish) >= n) {
            T x_copy = x;
            const size_type elems_after = finish - position;
            iterator old_finish = finish;
            if (elems_after > n) {
                // 插入的空间>n
                bss::uninitialized_copy(finish - n, finish, finish);
                finish += n;
                bss::copy_backward(position, old_finish - n, old_finish);
                bss::fill(position, position + n, x_copy);

            } else {
                bss::uninitialized_fill_n(finish, n - elems_after, x_copy);
                finish += n - elems_after;
                bss::uninitialized_copy(position, old_finish, finish);
                finish += elems_after;
                bss::fill(position, old_finish, x_copy);

            }


        } else {
            const size_type old_size = size();
            const size_type len = old_size + bss::max(old_size, n);  //2±¶
            iterator new_start = data_allocator::allocate(len);
            iterator new_finish = new_start;

            new_finish = bss::uninitialized_copy(start, position, new_start);
            new_finish = bss::uninitialized_fill_n(new_finish, n, x);
            new_finish = bss::uninitialized_copy(position, finish, new_finish);

            destroy(start, finish);
            deallocate();
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start + len;
        }
    }
}

template<class T, class Alloc>
void vector<T, Alloc>::insert_aux(iterator position, const T &x) {
    if (finish != end_of_storage) {
        construct(finish, *(finish - 1));
        ++finish;
        T x_copy = x;
        bss::copy_backward(position, finish - 2, finish - 1);
        *position = x_copy;
    } else {
        const size_type old_size = size();
        const size_type len = old_size != 0 ? 2 * old_size : 1;
        iterator new_start = data_allocator::allocate(len);
        iterator new_finish = new_start;

        new_finish = bss::uninitialized_copy(start, position, new_start);
        construct(new_finish, x);
        ++new_finish;
        new_finish = bss::uninitialized_copy(position, finish, new_finish);

        destroy(begin(), end());
        deallocate();
        start = new_start;
        finish = new_finish;
        end_of_storage = new_start + len;
    }
}

#endif //PLAY_WITH_ALGO_STL_VECTOR_H
