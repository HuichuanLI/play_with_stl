//
// Created by 李汇川 on 2022/6/5.
//

#ifndef PLAY_WITH_ALGO_MY_STL_DEQUE_H_
#define PLAY_WITH_ALGO_MY_STL_DEQUE_H_
#include "xmemory.h"

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
   public:
    iterator() : _First(0), _Last(0), _Next(0), _Map(0) {}

   protected:
    pointer _First, _Last, _Next;
    _Mapptr _Map;
  };

  explicit deque(const _A &_A1 = _A())
      : allocator(_A1), _First(), _Last(), _Map(0), _Mapsize(0), _Size(0) {}
      
 private:
  _A allocator;
  iterator _First, _Last;
  _Mapptr _Map;
  size_type _Mapsize, _Size;
}
#endif //PLAY_WITH_ALGO_MY_STL_DEQUE_H_
