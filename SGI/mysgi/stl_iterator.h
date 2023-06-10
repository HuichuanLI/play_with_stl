#pragma once


namespace bss {
    struct input_iterator_tag {
    };
    struct output_iterator_tag {
    };
    struct forward_iterator_tag : public input_iterator_tag {
    };
    struct bidirectional_iterator_tag : public forward_iterator_tag {
    };
    struct random_access_iterator_tag : public bidirectional_iterator_tag {
    };

    template<class T>
    T *value_type(const T *) {
        return (T *) (0);
    }

    template<class T>
    ptrdiff_t *distance_type(const T *) {
        return (ptrdiff_t *) (0);
    }


    template<class T>
    random_access_iterator_tag iterator_category(const T *) {
        return random_access_iterator_tag();
    }


    //distance
    template<class InputIterator, class Distance>
    void __distance(InputIterator first, InputIterator last, Distance &n, input_iterator_tag) {
        while (first != last) {
            ++first;
            ++n;
        }
    }

    template<class RandomAccessIterator, class Distance>
    void __distance(RandomAccessIterator first, RandomAccessIterator last, Distance &n, random_access_iterator_tag) {
        n += last - first;
    }

    template<class InputIterator, class Distance>
    void distance(InputIterator first, InputIterator last, Distance &n) {
        __distance(first, last, n, iterator_category(first));
    }
}