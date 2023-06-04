//
// Created by lhc456 on 2023/6/4.
//

#ifndef PLAY_WITH_ALGO_STL_CONSTRUCT_H
#define PLAY_WITH_ALGO_STL_CONSTRUCT_H

#include"stl_iterator.h"

//construct
template<class T1, class T2>
void construct(T1 *p, const T2 &value) {
    new(p)T1(value);  //placement new
}


#endif //PLAY_WITH_ALGO_STL_CONSTRUCT_H
