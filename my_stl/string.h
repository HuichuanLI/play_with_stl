//
// Created by 李汇川 on 2022/6/11.
//

#ifndef PLAY_WITH_ALGO_MY_STL_STRING_H_
#define PLAY_WITH_ALGO_MY_STL_STRING_H_
#include"xmemory.h"

template<class _E, class _Tr = char_traits<_E>, class _A = myallocator<_E> >
class mybasic_string {
 public:
  typedef mybasic_string<_E, _Tr, _A> _Myt;
  typedef size_t size_type;
  typedef int difference_type;
  typedef _E *pointer;
  typedef const _E *const_pointer;
  typedef _E &reference;
  typedef const _E &const_reference;
  typedef _E value_type;

  typedef pointer iterator;
  typedef const_pointer const_iterator;
 public:
  explicit mybasic_string(const _A &_Al = _A()) : allocator(_Al) {
    _Tidy();
  }
  mybasic_string(const _E *_S, const _A &_Al = _A()) : allocator(_Al) {
    _Tidy(), assign(_S);
  }
  mybasic_string(const _Myt &_X) : allocator(_X.allocator) {
    _Tidy(), assign(_X, 0, npos);
  }
  ~mybasic_string() {
    _Tidy(true);
  }
 public:
  size_type length() const { return _Len; }
  size_type size() const { return _Len; }
  size_type capacity() const { return (_Res); }
  const _E *c_str() const { return (_Ptr == 0 ? _Nullstr() : _Ptr); }
 public:
  reference operator[](size_type _P0) {
    if (_Len < _P0 || _Ptr == 0)
      return ((reference) *_Nullstr());
    _Freeze();
    return (_Ptr[_P0]);
  }
 public:
  _Myt &assign(const _Myt &_X, size_type _P, size_type _M) {
    if (_X.size() < _P)
      _Xran();
    size_type _N = _X.size() - _P;
    if (_M < _N)
      _N = _M;
    if (this == &_X)
      erase((size_type) (_P + _N)), erase(0, _P);
    else if (0 < _N && _N == _X.size()
        && _Refcnt(_X.c_str()) < _FROZEN - 1
        && allocator == _X.allocator) {
      _Tidy(true);
      _Ptr = (_E *) _X.c_str();
      _Len = _X.size();
      _Res = _X.capacity();
      ++_Refcnt(_Ptr);
    } else if (_Grow(_N, true)) {
      _Tr::copy(_Ptr, &_X.c_str()[_P], _N);
      _Eos(_N);
    }
    return (*this);
  }
  _Myt &assign(const _E *_S, size_type _N) {
    if (_Grow(_N, true)) {
      _Tr::copy(_Ptr, _S, _N);
      _Eos(_N);
    }
    return (*this);
  }
  _Myt &assign(const _E *_S) {
    return (assign(_S, _Tr::length(_S)));
  }
 public:
  _Myt &erase(size_type _P0 = 0, size_type _M = npos) {
    if (_Len < _P0)
      _Xran();
    _Split();
    if (_Len - _P0 < _M)
      _M = _Len - _P0;
    if (0 < _M) {
      _Tr::move(_Ptr + _P0, _Ptr + _P0 + _M,
                _Len - _P0 - _M);
      size_type _N = _Len - _M;
      if (_Grow(_N))
        _Eos(_N);
    }
    return (*this);
  }
  iterator begin() {
    return (_Ptr);
  }
  iterator end() {
    return (_Ptr + _Len);
  }

  iterator erase(iterator _P) {
    size_t _M = _Pdif(_P, begin());
    erase(_M, 1);
    return (_Psum(_Ptr, _M));
  }
  iterator erase(iterator _F, iterator _L) {
    size_t _M = _Pdif(_F, begin());
    erase(_M, _Pdif(_L, _F));
    return (_Psum(_Ptr, _M));
  }
 public:
  size_type max_size() const {
    size_type _N = allocator.max_size();
    return (_N <= 2 ? 1 : _N - 2);
  }
 public:
  enum _Mref { _FROZEN = 255 };
  static const size_type npos;  // -1
 protected:
  _A allocator;
 private:
  enum { _MIN_SIZE = sizeof(_E) <= 32 ? 31 : 7 };
  void _Split() {
    if (_Ptr != 0 && _Refcnt(_Ptr) != 0 && _Refcnt(_Ptr) != _FROZEN) {
      _E *_Temp = _Ptr;
      _Tidy(true);
      assign(_Temp);
    }
  }
  static const _E *__cdecl _Nullstr() {
    static const _E _C = _E(0);
    return (&_C);
  }
  //End of string
  void _Eos(size_type _N) {
    _Tr::assign(_Ptr[_Len = _N], _E(0));
  }
  void _Copy(size_type _N) {
    size_type _Ns = _N | _MIN_SIZE;
    if (max_size() < _Ns)
      _Ns = _N;
    _E *_S;
    /*
    _TRY_BEGIN
        _S = allocator.allocate(_Ns + 2, (void *)0);
    _CATCH_ALL
        _Ns = _N;
        _S = allocator.allocate(_Ns + 2, (void *)0);
    _CATCH_END
    */

    _S = allocator.allocate(_Ns + 2, (void *) 0);
    if (0 < _Len)
      _Tr::copy(_S + 1, _Ptr, _Len > _Ns ? _Ns : _Len);
    size_type _Olen = _Len;
    _Tidy(true);
    _Ptr = _S + 1;
    _Refcnt(_Ptr) = 0;
    _Res = _Ns;
    _Eos(_Olen > _Ns ? _Ns : _Olen);
  }
  void _Freeze() {
    if (_Ptr != 0
        && _Refcnt(_Ptr) != 0 && _Refcnt(_Ptr) != _FROZEN)
      _Grow(_Len);
    if (_Ptr != 0)
      _Refcnt(_Ptr) = _FROZEN;
  }
  bool _Grow(size_type _N, bool _Trim = false) {
    if (max_size() < _N)
      this->_Xran();
    if (_Ptr != 0 && _Refcnt(_Ptr) != 0 && _Refcnt(_Ptr) != _FROZEN) {
      if (_N == 0) {
        --_Refcnt(_Ptr), _Tidy();
        return (false);
      } else {
        _Copy(_N);
        return (true);
      }
    }
    if (_N == 0) {
      if (_Trim)
        _Tidy(true);
      else if (_Ptr != 0)
        _Eos(0);
      return (false);
    } else {
      if (_Trim && (_MIN_SIZE < _Res || _Res < _N)) {
        _Tidy(true);
        _Copy(_N);
      } else if (!_Trim && _Res < _N)
        _Copy(_N);
      return (true);
    }
  }
  unsigned char &_Refcnt(const _E *_U) {
    return (((unsigned char *) _U)[-1]);
  }
  void _Tidy(bool _Built = false) {
    if (!_Built || _Ptr == 0);
    else if (_Refcnt(_Ptr) == 0 || _Refcnt(_Ptr) == _FROZEN)
      allocator.deallocate(_Ptr - 1, _Res + 2);
    else
      --_Refcnt(_Ptr);
    _Ptr = 0, _Len = 0, _Res = 0;
  }
  void _Xran() const {
    throw ("invalid vector<bool> subscript");
  }
  _E *_Ptr;
  size_type _Len, _Res;
};

typedef mybasic_string<char, char_traits<char>, allocator<char> > mystring;
template<class _E, class _Tr, class _A>
const typename mybasic_string<_E, _Tr, _A>::size_type mybasic_string<_E, _Tr, _A>::npos = -1;
#endif //PLAY_WITH_ALGO_MY_STL_STRING_H_
