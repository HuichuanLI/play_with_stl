//
// Created by 李汇川 on 2022/6/5.
//

#ifndef PLAY_WITH_ALGO_MY_STL_DEQUE_H_
#define PLAY_WITH_ALGO_MY_STL_DEQUE_H_
#include "xmemory.h"

#define _DEQUEMAPSIZ    2
#define _DEQUESIZ (4096 < sizeof (_Ty) ? 1 : 4096 / sizeof (_Ty))

template<class _Ty, class _A=myallocator<_Ty> >
class deque {
 public:
  typedef typename _A::size_type size_type;
  typedef typename _A::difference_type difference_type;
  typedef typename _A::pointer pointer;
  typedef typename _A::const_pointer const_pointer;
  typedef typename _A::reference reference;
  typedef typename _A::const_reference const_reference;
  typedef typename _A::value_type value_type;

  typedef _A allocator_type;

  typedef pointer *_Mapptr; //int ** _Mapptr;
 public:
  size_type size() const { return _Size; }
  bool empty() const { return size() == 0; }

  class iterator {
    friend class deque<_Ty, _A>;
   public:
    iterator() : _First(0), _Last(0), _Next(0), _Map(0) {}
    iterator(pointer _P, _Mapptr _M)
        : _First(*_M), _Last(*_M + _DEQUESIZ), _Next(_P), _Map(_M) {}
   protected:
    pointer _First, _Last, _Next;
    _Mapptr _Map;
  };

  void push_front(const _Ty &_X) {
    if (empty() || _First._Next == _First._First)
      _Buyfront();
    allocator.construct(--_First._Next, _X);
    ++_Size;
  }

  void push_back(const _Ty &_X) {
    if (empty() || _Last._Next == _Last._Last) { // 空间不足
      _Buyback(); //
      allocator.construct(_Last._Next++, _X);
    } else if (_Last._Next + 1 == _Last._Last) // 只有一个空间
    {
      allocator.construct(_Last._Next++, _X);
      _Buyback();
    } else //空间充足
    {
      allocator.construct(_Last._Next++, _X);
    }
  }

  void pop_front() {
    allocator.destroy(_First._Next++);
    --_Size;
    if (empty() || _First._Next == _First._Last)
      _Freefront();
  }
  void pop_back() {
    if (_Last._Next == _Last._First)
      _Freeback();
    if (!empty())
      allocator.destroy(--_Last._Next);
    --_Size;
    if (empty())
      _Freeback();
  }

  explicit deque(const _A &_A1 = _A())
      : allocator(_A1), _First(), _Last(), _Map(0), _Mapsize(0), _Size(0) {}
 protected:
  void _Buyfront() {
    pointer _P = allocator.allocate(_DEQUESIZ, (void *) 0);
    if (empty()) {
      _Mapsize = _DEQUEMAPSIZ;
      size_type _N = _Mapsize / 2;
      _Getmap();
      _Setptr(_Map + _N, _P);
      _First = iterator(_P + (_DEQUESIZ / 2 + 1),
                        _Map + _N);
      _Last = _First;
    } else if (_Map < _First._Map) {
    } else if (_Last._Map == _First._Map) {
    } else {
      difference_type _I = _Last._Map - _First._Map + 1; //2
      _Mapptr _M = _Growmap(2 * _I);
      _Setptr(--_M, _P);
      _First = iterator(_P + _DEQUESIZ, _M);
      _Last = iterator(_Last._Next, _M + _I);
    }
  }
  void _Buyback() {
    pointer _P = allocator.allocate(_DEQUESIZ, (void *) 0);
    if (empty()) {
      _Mapsize = _DEQUEMAPSIZ;
      size_type _N = _Mapsize / 2;
      _Getmap();
      _Setptr(_Map + _N, _P);
      _First = iterator(_P + _DEQUESIZ / 2, _Map + _N);
      _Last = _First;
    } else if (_Last._Map < _Map + (_Mapsize - 1)) { // _Map还有空间了
      _Setptr(++_Last._Map, _P);
      _Last = iterator(_P, _Last._Map);
    } else {
      difference_type _I = _Last._Map - _First._Map + 1; // 1 _Map
      _Mapptr _M = _Growmap(2 * _I);
      _Setptr(_M + _I, _P);
      _First = iterator(_First._Next, _M);
      _Last = iterator(_P, _M + _I);
    }
  }
  void _Getmap() { _Map = (_Mapptr) allocator._Charalloc(_Mapsize * sizeof(pointer)); }
  void _Setptr(_Mapptr _M, pointer _P) { *_M = _P; }

  _Mapptr _Growmap(size_type _Newsize) {
    _Mapptr _M = (_Mapptr) allocator._Charalloc(_Newsize * sizeof(pointer));
    copy(_First._Map, _Last._Map + 1, _M + _Newsize / 4);
    allocator.deallocate(_Map, _Mapsize);
    _Map = _M;
    _Mapsize = _Newsize;
    return (_M + _Newsize / 4);

  }
  void _Freeptr(_Mapptr _M) { allocator.deallocate(*_M, _DEQUESIZ); }
 private:
  _A allocator;
  iterator _First, _Last;
  _Mapptr _Map;
  size_type _Mapsize, _Size;
}
#endif //PLAY_WITH_ALGO_MY_STL_DEQUE_H_
