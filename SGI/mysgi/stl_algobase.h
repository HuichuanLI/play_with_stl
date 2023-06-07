//
// Created by lhc456 on 2023/6/4.
//

#ifndef PLAY_WITH_ALGO_STL_ALGOBASE_H
#define PLAY_WITH_ALGO_STL_ALGOBASE_H

namespace bss {
    template<class T>
    const T &max(const T &a, const T &b) {
        return a < b ? b : a;
    }


    template<class OutputIterator, class Size, class T>
    OutputIterator fill_n(OutputIterator first, Size n, const T &value) {
        for (; n > 0; --n, ++first)
            *first = value;
        return first;
    }

    template<class RandomAccessIterator, class OutputIterator, class Distance>
    OutputIterator __copy_d(RandomAccessIterator first, RandomAccessIterator last,
                            OutputIterator result, Distance *) {
        for (Distance n = last - first; n > 0; --n, ++result, ++first)
            *result = *first;
        return result;
    }

    template<class RandomAccessIterator, class OutputIterator>
    OutputIterator __copy(RandomAccessIterator first, RandomAccessIterator last,
                          OutputIterator result, random_access_iterator_tag) {
        return __copy_d(first, last, result, distance_type(first));
    }

    template<class InputIterator, class OutputIterator>
    struct __copy_dispatch {
        OutputIterator operator()(InputIterator first, InputIterator last,
                                  OutputIterator result) {
            return __copy(first, last, result, iterator_category(first));
        }
    };

    template<class InputIterator, class OutputIterator>
    inline OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
        return __copy_dispatch<InputIterator, OutputIterator>()(first, last, result);
    }


}
#endif //PLAY_WITH_ALGO_STL_ALGOBASE_H
