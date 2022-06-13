//
// Created by 李汇川 on 2022/6/11.
//

#ifndef PLAY_WITH_ALGO_MY_STL_BISET_H_
#define PLAY_WITH_ALGO_MY_STL_BISET_H_
#include <iostream>
#include <string>
template<std::size_t _N>

class mybiset {
 public:
  typedef unsigned long _Ty;

  class reference {
    friend class mybiset<_N>;
   public:
    reference &operator=(bool _X) {
      _Pbs->set(_Off, _X);
      return *this;
    }
    reference &operator=(const reference &_Bs) {
      _Pbs->set(_Off, bool(_Bs));
      return *this;
    }
    reference &flip() {
      _Pbs->flip(_Off);
      return *this;
    }
    bool operator~() const { return (!_Pbs->test(_Off)); }
    operator bool() const {
      return _Pbs->test(_Off);
    }

   private:
    reference(mybiset<_N> &_X, size_t _P) : _Pbs(&_X), _Off(_P) {}
    mybiset<_N> *_Pbs;
    size_t _Off;
  };

 public:
  bool at(size_t _P) const {
    if (_N <= _P)
      _Xran();
    return (test(_P));
  }
  reference at(size_t _P) {
    if (_N <= _P)
      _Xran();
    return reference(*this, _P);
  }
  bool operator[](size_t _P) const {
    return (test(_P));
  }
  reference operator[](size_t _P) {
    return reference(*this, _P);
  }
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
  mybiset<_N> &flip() {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] = ~_A[_I];
    _Trim();
    return *this;
  }
  mybiset<_N> &flip(size_t _P) {
    if (_N <= _P)
      _Xran();
    _A[_P / _Nb] ^= (_Ty) 1 << _P % _Nb;
    return *this;
  }

  mybiset<_N> &reset() {
    _Tidy();
    return *this;
  }
  mybiset<_N> reset(size_t _P) {
    return set(_P, 0);
  }

  mybiset<_N> operator~() const {
    return mybiset<_N>(*this).flip();
  }

  mybiset() {
    _Tidy();
  }
  mybiset(unsigned long _X) {
    _Tidy();
    for (size_t _P = 0; _X != 0 && _P < _N; _X >>= 1, ++_P) {
      if (_X & 1)
        set(_P);
    }
  }
  explicit mybiset(const std::string &_S, size_t _P = 0, size_t _L = (size_t) (-1)) {
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
  mybiset<_N> &set() {
    _Tidy(~(_Ty) 0);
    return (*this);
  }
  mybiset<_N> &set(size_t _P, bool _X = true) {
    if (_N <= _P)
      _Xran();
    if (_X)
      _A[_P / _Nb] |= (_Ty) 1 << _P % _Nb;   //1
    else
      _A[_P / _Nb] &= ~((_Ty) 1 << _P % _Nb); //0
    return (*this);
  }

  friend std::ostream &operator<<(std::ostream &_O, const mybiset<_N> &_R) {
    for (size_t _P = _N; 0 < _P;)
      _O << (_R.test(--_P) ? '1' : '0');
    return (_O);
  }

  _Ty _W(size_t _I) const { return (_A[_I]); }

  mybiset<_N> &operator&=(const mybiset<_N> &_R) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] &= _R._W(_I);
    return *this;
  }

  mybiset<_N> &operator|=(const mybiset<_N> &_R) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] |= _R._W(_I);
    return *this;
  }
  mybiset<_N> &operator^=(const mybiset<_N> &_R) {
    for (int _I = _Nw; 0 <= _I; --_I)
      _A[_I] ^= _R._W(_I);
    return *this;
  }
  mybiset<_N> &operator<<=(size_t _P) {
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
  bool test(size_t _P) const {
    if (_N <= _P)
      _Xran();
    return ((_A[_P / _Nb] & ((_Ty) 1 << _P % _Nb)) != 0);
  }
  /////////////////////////////////////////////////////////////
  mybiset<_N> &operator>>=(size_t _P) {
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
  mybiset<_N> operator<<(size_t _R) const  //bt1 = bt << 8
  {
    return (mybiset<_N>(*this) <<= _R);
  }
  mybiset<_N> operator>>(size_t _R) const {
    return (mybiset<_N>(*this) >>= _R);
  }
  friend mybiset<_N> operator&(const mybiset<_N> &_L, const mybiset<_N> &_R) {
    return (mybiset<_N>(_L) &= _R);
  }
  friend mybiset<_N> operator|(const mybiset<_N> &_L, const mybiset<_N> &_R) {
    return (mybiset<_N>(_L) |= _R);
  }
  friend mybiset<_N> operator^(const mybiset<_N> &_L, const mybiset<_N> &_R) {
    return (mybiset<_N>(_L) ^= _R);
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
    throw ("invalid mybiset<N> char");
  }
  void _Xoflo() const {
    throw ("mybiset<N> conversion overflow");
  }

  void _Xran() const {
    throw ("invalid mybiset<N> position");
  }
  _Ty _A[_Nw + 1]; //_Ty _A[4]
};
#endif //PLAY_WITH_ALGO_MY_STL_BISET_H_
