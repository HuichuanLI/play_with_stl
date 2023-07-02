//
// Created by lhc456 on 2023/7/1.
//

#ifndef PLAY_WITH_ALGO_STL_HASH_FUN_H
#define PLAY_WITH_ALGO_STL_HASH_FUN_H

#include "stdlib.h"

namespace bss {
    template<class Key>
    struct hash {
    };

    size_t __stl_hash_string(const char *s) {
        unsigned long h = 0;
        for (; *s; ++s)
            h = 5 * h + *s;

        return size_t(h);
    }

    template<>
    struct hash<int> {
        size_t operator()(int x) const {
            return x;
        }
    };

    template<>
    struct hash<char *> {
        size_t operator()(const char *s) const {
            return __stl_hash_string(s);
        }
    };
}
#endif //PLAY_WITH_ALGO_STL_HASH_FUN_H
