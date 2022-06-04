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

  }

 protected:

  _Nodeptr _Buynode() {
    //_Nodeptr _S = (_Nodeptr) malloc(sizeof(_Node));
    _Nodeptr _S = (_Nodeptr) malloc(sizeof(_Node));
    //_Nodeptr _S = (_Nodeptr)operator new(sizeof(_Node));
    //_Nodeptr _S = (_Nodeptr)allocator.allocate(1, 0);
    assert(_S != NULL);
    _S->_Next = _S;
    _S->_Prev = _S;
    return _S;
  }

 private:
  _Nodeptr _Head;
  size_type _Size;

};

#endif //PLAY_WITH_STL_MY_STL_LIST_H_
