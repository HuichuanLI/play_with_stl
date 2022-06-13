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
 public:
  size_t size() const {
    return _N;
  }
  bool any() const {
    for (int _I = _Nw; 0 <= _I; --_I) {
      if (_A[0] != 0)
        return true;
    }
    return false;
  }
  bool none() const { return !any(); }

  size_t count() const {
    size_t _V = 0;
    for (int _I = _Nw; 0 <= _I; --_I) {
      for (_Ty _X = _A[_I]; _X != 0; _X >>= 4) {
        _V += "\0\1\1\2\1\2\2\3"
              "\1\2\2\3\2\3\3\4"[_X & 0xF];
      }
    }
    return _V;
  }
  bitset<_N> &flip() {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] = ~_A[_I];
    _Trim();
    return *this;
  }
  bitset<_N> &flip(size_t _P) {
    if (_N <= _P)
      _Xran();
    _A[_P / _Nb] ^= (_Ty) 1 << _P % _Nb;
    return *this;
  }

  bitset<_N> &reset() {
    _Tidy();
    return *this;
  }
  bitset<_N> reset(size_t _P) {
    return set(_P, 0);
  }

  bitset<_N> operator~() const {
    return bitset<_N>(*this).flip();
  }

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
  bitset<_N> &set() {
    _Tidy(~(_Ty) 0);
    return (*this);
  }
  bitset<_N> &set(size_t _P, bool _X = true) {
    if (_N <= _P)
      _Xran();
    if (_X)
      _A[_P / _Nb] |= (_Ty) 1 << _P % _Nb;   //1
    else
      _A[_P / _Nb] &= ~((_Ty) 1 << _P % _Nb); //0
    return (*this);
  }

  friend std::ostream &operator<<(std::ostream &_O, const bitset<_N> &_R) {
    for (size_t _P = _N; 0 < _P;)
      _O << (_R.test(--_P) ? '1' : '0');
    return (_O);
  }

  _Ty _W(size_t _I) const { return (_A[_I]); }

  bitset<_N> &operator&=(const bitset<_N> &_R) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] &= _R._W(_I);
    return *this;
  }

  bitset<_N> &operator|=(const bitset<_N> &_R) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] |= _R._W(_I);
    return *this;
  }
  bitset<_N> &operator^=(const bitset<_N> &_R) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] ^= _R._W(_I);
    return *this;
  }
  bitset<_N> &operator<<=(size_t _P) {
    if (_P < 0)
      return *this >>= -_P;
    const int _D = _P / _Nb;
    if (_D != 0) {
      for (int _I = _Nw; 0 <= _I; --_I) {
        _A[_I] = _D <= _I ? _A[_I - _D] : 0;
      }
    }
    if ((_P % _Nb) != 0) {
      for (int _I = _Nw; 0 < _I; --_I) {
        _A[_I] = (_A[_I] << _P) | (_A[_I - 1] >> (_Nb - _P));
      }
      _A[0] <<= _P, _Trim();
    }
    return *this;
  }
  /////////////////////////////////////////////////////////////
  bitset<_N> &operator>>=(size_t _P) {
    if (_P < 0)
      return (*this <<= -_P);
    const int _D = _P / _Nb;
    if (_D != 0) {
      for (int _I = 0; _I <= _Nw; ++_I)
        _A[_I] = _D <= _Nw - _I ? _A[_I + _D] : 0;
    }
    if ((_P %= _Nb) != 0) {
      for (int _I = 0; _I < _Nw; ++_I)
        _A[_I] = (_A[_I] >> _P) | (_A[_I + 1] << (_Nb - _P));
      _A[_Nw] >>= _P;
    }
    return (*this);
  }
  bitset<_N> operator<<(size_t _R) const  //bt1 = bt << 8
  {
    return (bitset<_N>(*this) <<= _R);
  }
  bitset<_N> operator>>(size_t _R) const {
    return (bitset<_N>(*this) >>= _R);
  }
  friend bitset<_N> operator&(const bitset<_N> &_L, const bitset<_N> &_R) {
    return (bitset<_N>(_L) &= _R);
  }
  friend bitset<_N> operator|(const bitset<_N> &_L, const bitset<_N> &_R) {
    return (bitset<_N>(_L) |= _R);
  }
  friend bitset<_N> operator^(const bitset<_N> &_L, const bitset<_N> &_R) {
    return (bitset<_N>(_L) ^= _R);
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
