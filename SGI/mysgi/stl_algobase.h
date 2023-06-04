//
// Created by lhc456 on 2023/6/4.
//

#ifndef PLAY_WITH_ALGO_STL_ALGOBASE_H
#define PLAY_WITH_ALGO_STL_ALGOBASE_H

namespace bss {
    template<class OutputIterator, class Size, class T>
    OutputIterator fill_n(OutputIterator first, Size n, const T &value) {
        for (; n > 0; --n, ++first)
            *first = value;
        return first;
    }

}
#endif //PLAY_WITH_ALGO_STL_ALGOBASE_H
