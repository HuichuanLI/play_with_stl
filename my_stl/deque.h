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
  class iterator {
    friend class deque<_Ty, _A>;
   public:
    iterator() : _First(0), _Last(0), _Next(0), _Map(0) {}
    iterator(pointer _P, _Mapptr _M)
        : _First(*_M), _Last(*_M + _DEQUESIZ), _Next(_P), _Map(_M) {}
    reference operator*() { return *_Next; }
    pointer operator->() { return &**this; }
    iterator &operator++() {
      if (++_Next == _Last) {
        _First = *++_Map;
        _Last = _First + _DEQUESIZ;
        _Next = _First;
      }
      return *this;
    }
    iterator operator++(int) {
      iterator _Tmp = *this;
      ++*this;
      return _Tmp;
    }
    iterator &operator--() {
      if (_Next == _First) {
        _First = *--_Map;
        _Last = _First + _DEQUESIZ;
        _Next = _Last;
      }
      --_Next;
      return *this;
    }
    iterator operator--(int) {
      iterator _Tmp = *this;
      --*this;
      return _Tmp;
    }
    iterator &operator+=(difference_type _N) {
      _Add(_N);
      return *this;
    }
    iterator &operator-=(difference_type _N) { return *this += -_N; }

    iterator operator+(difference_type _N) {
      iterator _Tmp = *this;
      return (_Tmp += _N);
    }
    iterator operator-(difference_type _N) {
      iterator _Tmp = *this;
      return (_Tmp -= _N);
    }

    reference operator[](difference_type _N) { return (*(*this + _N)); }

    difference_type operator-(const iterator &_X) const {
      return (_Map == _X._Map ? _Next - _X._Next
                              : _DEQUESIZ * (_Map - _X._Map - 1)
                  + (_Next - _First) + (_X._Last - _X._Next));
    }

    bool operator==(const iterator &_X) { return _Next == _X._Next; }
    bool operator!=(const iterator &_X) { return !(*this == _X); }
   protected:
    void _Add(difference_type _N) {
      difference_type _Off = _N + _Next - _First; // 5 + 7 = 12
      difference_type _Moff = (_Off >= 0) ? _Off / _DEQUESIZ : -((_DEQUESIZ - 1 - _Off) / _DEQUESIZ);
      if (_Moff == 0)
        _Next += _N;
      else {
        _Map += _Moff;
        _First = *_Map;
        _Last = _First + _DEQUESIZ;
        _Next = _First + (_Off - _Moff * _DEQUESIZ);
      }
    }
   protected:
    pointer _First, _Last, _Next;
    _Mapptr _Map;
  };
  typedef iterator _It;

  iterator begin() { return _First; }
  iterator end() { return _Last; }
  size_type size() const { return _Size; }
  bool empty() const { return size() == 0; }

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

  void _Freefront() {
    _Freeptr(_First._Map++);
    if (empty()) {
      _First = iterator();
      _Last = _First;
      _Freemap();
    } else
      _First = iterator(*_First._Map, _First._Map);
  }

  void _Freeback() {
    _Freeptr(_Last._Map--);
    if (empty()) {
      if (_First._Map == _Last._Map)
        _Freeptr(_First._Map);
      _First = iterator();
      _Last = _First;
      _Freemap();
    } else
      _Last = iterator(*_Last._Map + _DEQUESIZ, _Last._Map);
  }
  void _Freemap() { allocator.deallocate(_Map, _Mapsize); }
 private:
  _A allocator;
  iterator _First, _Last;
  _Mapptr _Map;
  size_type _Mapsize, _Size;
};
#endif //PLAY_WITH_ALGO_MY_STL_DEQUE_H_
