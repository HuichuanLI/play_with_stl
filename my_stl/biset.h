//
// Created by 李汇川 on 2022/6/11.
//

#ifndef PLAY_WITH_ALGO_MY_STL_BISET_H_
#define PLAY_WITH_ALGO_MY_STL_BISET_H_
#include <iostream>
#include <string>
template<std::size_t _N>

class bitset {
 public:
  typedef unsigned long _Ty;
  //number bit                    number word
  //32
  enum { _Nb = CHAR_BIT * sizeof(_Ty), _Nw = _N == 0 ? 0 : (_N - 1) / _Nb };
 public:
  bitset() {
    _Tidy();
  }
  bitset(unsigned long _X) {
    _Tidy();
    for (size_t _P = 0; _X != 0 && _P < _N; _X >>= 1, ++_P) {
      if (_X & 1)
        set(_P);
    }
  }
  explicit bitset(const std::string &_S, size_t _P = 0, size_t _L = (size_t) (-1)) {
    size_t _I;
    if (_S.size() < _P)
      _Xran();
    if (_S.size() - _P < _L)
      _L = _S.size() - _P;
    if (_N < _L)
      _L = _N;
    _Tidy(), _P += _L;
    for (_I = 0; _I < _L; ++_I)
      if (_S[--_P] == '1')
        set(_I);
      else if (_S[_P] != '0')
        _Xinv();
  }
 private:
  //number bit                    number word
  //32
  enum { _Nb = CHAR_BIT * sizeof(_Ty), _Nw = _N == 0 ? 0 : (_N - 1) / _Nb };
  void _Tidy(_Ty _X = 0) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] = _X;
    if (_X != 0)
      _Trim();
  }
  void _Trim() {
    if (_N % _Nb != 0)
      _A[_Nw] &= ((_Ty) 1 << _N % _Nb) - 1;
  }
  void _Xinv() const {
    throw ("invalid bitset<N> char");
  }
  void _Xoflo() const {
    throw ("bitset<N> conversion overflow");
  }

  void _Xran() const {
    throw ("invalid bitset<N> position");
  }
  _Ty _A[_Nw + 1]; //_Ty _A[4]
}
#endif //PLAY_WITH_ALGO_MY_STL_BISET_H_
