//
// Created by 李汇川 on 2022/6/4.
//

#ifndef PLAY_WITH_STL_MY_STL_LIST_H_
#define PLAY_WITH_STL_MY_STL_LIST_H_
#include <cstddef>
#include <cstdlib>
#include <assert.h>
#include <iostream>
#include "xmemory.h"

template<class _Ty, class _A=myallocator<_Ty>>
class list {
 public:
  struct _Node;
  typedef _Node *_Nodeptr;

  struct _Node {
    _Nodeptr _Next, _Prev;
    _Ty _Value;
  };

  struct _Acc {
    typedef _Nodeptr &_Nodepref;
    typedef _Ty &_Vref;
    static _Nodepref _Next(_Nodeptr _P) { return ((_Nodepref) (*_P)._Next); } //_P->_Next;
    static _Nodepref _Prev(_Nodeptr _P) { return ((_Nodepref) (*_P)._Prev); }
    static _Vref _Value(_Nodeptr _P) { return ((_Vref) (*_P)._Value); }
  };

  typedef typename _A::size_type size_type;
  typedef typename _A::difference_type difference_type;
  typedef typename _A::pointer pointer;
  typedef typename _A::const_pointer const_pointer;
  typedef typename _A::reference reference;
  typedef typename _A::const_reference const_reference;
  typedef typename _A::value_type value_type;

  class const_iterator {
   public:
    const_iterator() {}
    const_iterator(_Nodeptr _P) : _Ptr(_P) {}
    const_iterator(const_iterator &_X) : _Ptr(_X._Ptr) {}
    const_reference operator*() const { return _Acc::_Value(_Ptr); }
    //++it   it++
    const_iterator operator++() {
      _Ptr = _Acc::_Next(_Ptr); // _Ptr = _Ptr->_Next;
      return *this;
    }
    const_iterator operator++(int) {
      const_iterator _Tmp = *this;
      ++*this;
      return _Tmp;
    }
    const_iterator operator--() {
      _Ptr = _Acc::_Prev(_Ptr);
      return *this;
    }
    const_iterator operator--(int) {
      const_iterator _Tmp = *this;
      --*this;
      return _Tmp;
    }
    bool operator==(const const_iterator &_X) const { return _Ptr == _X._Ptr; }
    bool operator!=(const const_iterator &_X) const { return !(*this == _X); }

    _Nodeptr _Mynode() const { return _Ptr; }
   protected:
    _Nodeptr _Ptr;
  };

  class iterator : public const_iterator {
   public:
    iterator() {}

    iterator(_Nodeptr _P) {
      this->_Ptr = _P;
    }
    iterator(const iterator const &next) {
      this->_Ptr = next._Ptr;
    }
    reference operator*() { return _Acc::_Value(this->_Ptr); }

    //++it   it++
    iterator operator++() {
      this->_Ptr = _Acc::_Next(this->_Ptr); // _Ptr = _Ptr->_Next;
      return *this;
    }
    iterator operator++(int) {
      iterator _Tmp = *this;
      ++*this;
      return _Tmp;
    }
    iterator operator--() {
      this->_Ptr = _Acc::_Prev(this->_Ptr);
      return *this;
    }
    iterator operator--(int) {
      const_iterator _Tmp = *this;
      --*this;
      return _Tmp;
    }
    bool operator==(const iterator &_X) const { return this->_Ptr == _X._Ptr; }
    bool operator!=(const iterator &_X) const { return !(*this == _X); }
  };
  typedef const_iterator _It;

 public:
  explicit list() : _Head(_Buynode()), _Size(0) {}
  explicit list(size_type _N, const _Ty &_V = _Ty()) : _Head(_Buynode()), _Size(0) { insert(begin(), _N, _V); }
  list(const _Ty *_F, const _Ty *_L) : _Head(_Buynode()), _Size(0) { insert(begin(), _F, _L); }
  list(_It _F, _It _L) : _Head(_Buynode()), _Size(0) { insert(begin(), _F, _L); }
  ~list() {
    erase(begin(), end());
    _Freenode(_Head);
    _Head = 0;
    _Size = 0;
  }

 public:
  size_type size() const { return _Size; }
  bool empty() const { return (size() == 0); }
  reference front() { return *begin(); }
  reference back() { return *--end(); }
  void push_back(const _Ty &v) { insert(end(), v); }
  void push_front(const _Ty &v) { insert(begin(), v); }
  void pop_back() { erase(--end()); }
  void pop_front() { erase(begin()); }

//  iterator begin() { return iterator(_Acc::_Next(_Head)); }
  iterator begin() const {
    return iterator(_Acc::_Next(_Head));
  }
//  iterator end() { return iterator(_Head); }
  iterator end() const {
    return iterator(_Head);
  }
 public:
  iterator insert(iterator _P, const _Ty &_X = _Ty()) {
    _Nodeptr _S = _P._Mynode();
    _Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
    _S = _Acc::_Prev(_S);
    _Acc::_Next(_Acc::_Prev(_S)) = _S;

    /////////////////////////
    // _Acc::_Value(_S) = _X;
    allocator.construct(&_Acc::_Value(_S), _X);
    /////////////////////////
    _Size++;
    return iterator(_S);
  }

  void insert(iterator _P, size_type _M, const _Ty &_X) {
    for (; 0 < _M; --_M)
      insert(_P, _X);
  }
  void insert(iterator _P, const _Ty *_F, const _Ty *_L) {
    for (; _F != _L; ++_F)
      insert(_P, *_F);
  }
  void insert(iterator _P, _It _F, _It _L) {
    for (; _F != _L; ++_F)
      insert(_P, *_F);
  }

  iterator erase(iterator _F, iterator _L) {
    while (_F != _L)
      erase(_F++);
    return _F;
  }
  void clear() { erase(begin(), end()); }

  void assign(_It _F, _It L) {
    erase(begin(), end());
    insert(_F, L);
  }
  void assgin(size_type _N, const _Ty &_X = _Ty()) {
    erase(begin(), end());
    insert(begin(), _N, _X);
  }

 protected:
  //_Narg  next argument  _Parg prev argument
  _Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0) {
    //_Nodeptr _S = (_Nodeptr) malloc(sizeof(_Node));
//    _Nodeptr _S = (_Nodeptr) malloc(sizeof(_Node));
    //_Nodeptr _S = (_Nodeptr)operator new(sizeof(_Node));
    _Nodeptr _S = (_Nodeptr) allocator._Charalloc(sizeof(_Node));
    assert(_S != NULL);
    _Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
    _Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
    return _S;
  }

  iterator erase(iterator _P) {
    _Nodeptr _S = (_P++)._Mynode();
    _Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
    _Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);

    /////////////////////
//    free(_S);
    allocator.destroy(&_Acc::_Value(_S)); //destroy object
    _Freenode(_S);
    /////////////////////
    --_Size;
    return _P;
  }

  void _Freenode(_Nodeptr _S) {
    allocator.deallocate(_S, 1);
    //operatror delete(_S);
  }

 private:
  _A allocator;
  _Nodeptr _Head;
  size_type _Size;

};

#endif //PLAY_WITH_STL_MY_STL_LIST_H_
