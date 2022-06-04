//
// Created by 李汇川 on 2022/6/4.
//

#ifndef PLAY_WITH_STL_MY_STL_LIST_H_
#define PLAY_WITH_STL_MY_STL_LIST_H_
#include <cstddef>
#include <cstdlib>
#include <assert.h>
template<class _Ty>
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

  typedef size_t size_type;
  typedef _Ty value_type;
  typedef _Ty *pointer_type;
  typedef _Ty &reference_type;
  typedef const _Ty *const_pointer_type;
  typedef const _Ty &const_reference_type;
  typedef int difference_type;
 public:
  explicit list() : _Head(_Buynode()), _Size(0) {

  }
  void push_back(const _Ty &v) {

    _Nodeptr _S = _Buynode();
    _S->_Value = v;
    _S->_Prev = _Head->_Prev;
    _Head->_Prev->_Next = _S;
    _S->_Next = _Head;
    _Head->_Next = _S;
    _Size++;

  }

 protected:
  //_Narg  next argument  _Parg prev argument

  _Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0) {
    //_Nodeptr _S = (_Nodeptr) malloc(sizeof(_Node));
    _Nodeptr _S = (_Nodeptr) malloc(sizeof(_Node));
    //_Nodeptr _S = (_Nodeptr)operator new(sizeof(_Node));
    //_Nodeptr _S = (_Nodeptr)allocator.allocate(1, 0);
    assert(_S != NULL);
    _S->_Next = _Narg != 0 ? _Narg : _S;
    _S->_Prev = _Parg != 0 ? _Parg : _S;
    return _S;
  }

 private:
  _Nodeptr _Head;
  size_type _Size;

};

#endif //PLAY_WITH_STL_MY_STL_LIST_H_
