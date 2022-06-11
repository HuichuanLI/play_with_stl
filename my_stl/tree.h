//
// Created by 李汇川 on 2022/6/11.
//

#ifndef PLAY_WITH_ALGO_MY_STL_TREE_H_
#define PLAY_WITH_ALGO_MY_STL_TREE_H_
#include "xmemory.h"

//set  map  multiset  multimap
template<class _K, class _Ty, class _Kfn, class _Pr, class _A>
class _Tree {
  enum _Redbl { _Red, _Black };

  struct _Node;
  typedef _Node *_Nodeptr;
  struct _Node {
    _Nodeptr _Left, _Parent, _Right;
    _Ty _Value;
    _Redbl _Color;
  };

  typedef _Node *&_Nodepref;
  typedef const _K &_Keyref;
  typedef _Redbl &_Rbref;
  typedef _Ty &_Vref;

  static _Rbref _Color(_Nodeptr _P) { return ((_Rbref) (*_P)._Color); }
  static _Keyref _Key(_Nodeptr _P) { return (_Kfn()(_Value(_P))); }
  static _Nodepref _Left(_Nodeptr _P) { return ((_Nodepref) (*_P)._Left); }
  static _Nodepref _Parent(_Nodeptr _P) { return ((_Nodepref) (*_P)._Parent); }
  static _Nodepref _Right(_Nodeptr _P) { return ((_Nodepref) (*_P)._Right); }
  static _Vref _Value(_Nodeptr _P) { return ((_Vref) (*_P)._Value); }

 public:
  typedef _Tree<_K, _Ty, _Kfn, _Pr, _A> _Myt;
  typedef _K key_type;
  typedef _Ty value_type;
  typedef typename _A::size_type size_type;
  typedef typename _A::difference_type difference_type;
  typedef _Ty *pointer;
  typedef const _Ty *const_pointer;
  typedef _Ty &reference;
  typedef const _Ty &const_reference;
 public:
  class iterator;
  explicit _Tree(const _Pr &_Parg, bool _Marg = true, const _A &_Al = _A())
      : allocator(_Al), key_compare(_Parg), _Multi(_Marg) {
    _Init();
  }
 protected:
  _Nodeptr _Buynode(_Nodeptr _Parg, _Redbl _Carg) {
    _Nodeptr _S = (_Nodeptr) allocator._Charalloc(1 * sizeof(_Node));
    _Parent(_S) = _Parg;
    _Color(_S) = _Carg;
    return (_S);
  }
  void _Consval(pointer _P, const _Ty &_V) { _Construct(&*_P, _V); }
  void _Destval(pointer _P) { _Destroy(&*_P); }
  void _Freenode(_Nodeptr _S) { allocator.deallocate(_S, 1); }
  static _Nodeptr _Nil;  //1
  static size_t _Nilrefs;

  void _Init() {
    _Nodeptr _Tmp = _Buynode(0, _Black);
    {
      //_Lockit _Lk;  //lock 多线程
      if (_Nil == 0) {
        _Nil = _Tmp;
        _Tmp = 0;
        _Left(_Nil) = 0, _Right(_Nil) = 0;
      }
      ++_Nilrefs;
    }
    if (_Tmp != 0)
      _Freenode(_Tmp);
    _Head = _Buynode(_Nil, _Red), _Size = 0;
    _Lmost() = _Head, _Rmost() = _Head;
  }
  _Nodeptr &_Lmost() { return (_Left(_Head)); }
  _Nodeptr &_Rmost() { return (_Right(_Head)); }
  _Nodeptr &_Root() { return (_Parent(_Head)); }
 private:

  _A allocator;
  _Pr key_compare;
  _Nodeptr _Head;
  bool _Multi;
  size_type _Size;
};
template<class _K, class _Ty, class _Kfn, class _Pr, class _A>
typename _Tree<_K, _Ty, _Kfn, _Pr, _A>::_Nodeptr _Tree<_K, _Ty, _Kfn, _Pr, _A>::_Nil = 0;  //1

template<class _K, class _Ty, class _Kfn, class _Pr, class _A>
size_t _Tree<_K, _Ty, _Kfn, _Pr, _A>::_Nilrefs = 0;
#endif //PLAY_WITH_ALGO_MY_STL_TREE_H_


// 1。 null为空节点
// 2。 parent和root相互指向
// 3。 lmost指向第一个，rmost指向最后一个