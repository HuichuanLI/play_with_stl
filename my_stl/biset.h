//
// Created by 李汇川 on 2022/6/11.
//

#ifndef PLAY_WITH_ALGO_MY_STL_BISET_H_
#define PLAY_WITH_ALGO_MY_STL_BISET_H_
#include <iostream>
template<std::size_t _N>

class bitset {
 public:
  typedef unsigned long _Ty;
  //number bit                    number word
  //32
  enum { _Nb = CHAR_BIT * sizeof(_Ty), _Nw = _N == 0 ? 0 : (_N - 1) / _Nb };

}
#endif //PLAY_WITH_ALGO_MY_STL_BISET_H_
