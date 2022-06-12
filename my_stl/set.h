//
// Created by 李汇川 on 2022/6/12.
//

#ifndef PLAY_WITH_ALGO_MY_STL_SET_H_
#define PLAY_WITH_ALGO_MY_STL_SET_H_
#include"tree.h"
#include "xmemory.h"

template<class _K, class _Pr = less<_K>, class _A = myallocator<_K> >
class set {
 public:
  typedef set<_K, _Pr, _A> _Myt;
  typedef _K value_type;
  struct _Kfn {
    const _K &operator()(const value_type &_X) const { return (_X); }
  };
  typedef _Pr value_compare;
  typedef _K key_type;
  typedef _Pr key_compare;
  typedef _A allocator_type;

  typedef _Tree<_K, value_type, _Kfn, _Pr, _A> _Imp;

  typedef typename _Imp::size_type size_type;
  typedef typename _Imp::difference_type difference_type;
  typedef typename _Imp::reference reference;
  typedef typename _Imp::const_reference const_reference;
  typedef typename _Imp::iterator iterator;

  typedef pair<iterator, bool> _Pairib;
  typedef pair<iterator, iterator> _Pairii;
  explicit set(const _Pr &_Pred = _Pr(), const _A &_Al = _A()) : _Tr(_Pred, false, _Al) {}
  typedef const value_type *_It;
  set(_It _F, _It _L, const _Pr &_Pred = _Pr(),
      const _A &_Al = _A())
      : _Tr(_Pred, false, _Al) {
    for (; _F != _L; ++_F)
      _Tr.insert(*_F);
  }
  _Myt &operator=(const _Myt &_X) {
    _Tr = _X._Tr;
    return (*this);
  }
  iterator begin() { return (_Tr.begin()); }
  iterator end() { return (_Tr.end()); }

  size_type size() const { return (_Tr.size()); }
  size_type max_size() const { return (_Tr.max_size()); }
  bool empty() const { return (_Tr.empty()); }
  _A get_allocator() const { return (_Tr.get_allocator()); }
  _Pairib insert(const value_type &_X) {
    typename _Imp::_Pairib _Ans = _Tr.insert(_X);
    return (_Pairib(_Ans.first, _Ans.second));
  }
  iterator insert(iterator _P, const value_type &_X) { return (_Tr.insert((_Imp::iterator &) _P, _X)); }
  void insert(_It _F, _It _L) {
    for (; _F != _L; ++_F)
      _Tr.insert(*_F);
  }
  iterator erase(iterator _P) { return (_Tr.erase((_Imp::iterator &) _P)); }
  iterator erase(iterator _F, iterator _L) {
    return (_Tr.erase((_Imp::iterator &) _F,
                      (_Imp::iterator &) _L));
  }
  size_type erase(const _K &_Kv) { return (_Tr.erase(_Kv)); }
  void clear() { _Tr.clear(); }
  void swap(_Myt &_X) { std::swap(_Tr, _X._Tr); }
  friend void swap(_Myt &_X, _Myt &_Y) { _X.swap(_Y); }
  key_compare key_comp() const { return (_Tr.key_comp()); }
  value_compare value_comp() const { return (_Tr.key_comp()); }
  iterator find(const _K &_Kv) { return (_Tr.find(_Kv)); }
  size_type count(const _K &_Kv) const { return (_Tr.count(_Kv)); }
  iterator lower_bound(const _K &_Kv) { return (_Tr.lower_bound(_Kv)); }
  iterator upper_bound(const _K &_Kv) { return (_Tr.upper_bound(_Kv)); }
  _Pairii equal_range(const _K &_Kv) { return (_Tr.equal_range(_Kv)); }

 protected:
  _Imp _Tr;
};

template<class _K, class _Pr = less<_K>, class _A = allocator<_K> >
class multiset {
 public:
  typedef multiset<_K, _Pr, _A> _Myt;
  typedef _K value_type;
  struct _Kfn {
    const _K &operator()(const value_type &_X) const { return (_X); }
  };
  typedef _Pr value_compare;
  typedef _K key_type;
  typedef _Pr key_compare;
  typedef _A allocator_type;
  typedef _Tree<_K, value_type, _Kfn, _Pr, _A> _Imp;
  typedef typename _Imp::size_type size_type;
  typedef typename _Imp::difference_type difference_type;
  typedef typename _Imp::reference reference;
  typedef typename _Imp::const_reference const_reference;
  typedef typename _Imp::iterator iterator;

  typedef pair<iterator, iterator> _Pairii;
  explicit multiset(const _Pr &_Pred = _Pr(), const _A &_Al = _A()) : _Tr(_Pred, true, _Al) {}
  typedef const value_type *_It;
  multiset(_It _F, _It _L, const _Pr &_Pred = _Pr(),
           const _A &_Al = _A())
      : _Tr(_Pred, true, _Al) {
    for (; _F != _L; ++_F)
      _Tr.insert(*_F);
  }
  _Myt &operator=(const _Myt &_X) {
    _Tr = _X._Tr;
    return (*this);
  }
  iterator begin() { return (_Tr.begin()); }
  iterator end() { return (_Tr.end()); }
  size_type size() const { return (_Tr.size()); }
  size_type max_size() const { return (_Tr.max_size()); }
  bool empty() const { return (_Tr.empty()); }
  _A get_allocator() const { return (_Tr.get_allocator()); }
  iterator insert(const value_type &_X) { return (_Tr.insert(_X).first); }
  iterator insert(iterator _P, const value_type &_X) { return (_Tr.insert((_Imp::iterator &) _P, _X)); }
  void insert(_It _F, _It _L) {
    for (; _F != _L; ++_F)
      _Tr.insert(*_F);
  }
  iterator erase(iterator _P) { return (_Tr.erase((_Imp::iterator &) _P)); }
  iterator erase(iterator _F, iterator _L) {
    return (_Tr.erase((_Imp::iterator &) _F,
                      (_Imp::iterator &) _L));
  }
  size_type erase(const _K &_Kv) { return (_Tr.erase(_Kv)); }
  void clear() { _Tr.clear(); }
  void swap(_Myt &_X) { std::swap(_Tr, _X._Tr); }
  friend void swap(_Myt &_X, _Myt &_Y) { _X.swap(_Y); }
  key_compare key_comp() const { return (_Tr.key_comp()); }
  value_compare value_comp() const { return (_Tr.key_comp()); }
  iterator find(const _K &_Kv) { return (_Tr.find(_Kv)); }
  size_type count(const _K &_Kv) const { return (_Tr.count(_Kv)); }
  iterator lower_bound(const _K &_Kv) { return (_Tr.lower_bound(_Kv)); }
  iterator upper_bound(const _K &_Kv) { return (_Tr.upper_bound(_Kv)); }
  _Pairii equal_range(const _K &_Kv) { return (_Tr.equal_range(_Kv)); }
 protected:
  _Imp _Tr;
};

#endif //PLAY_WITH_ALGO_MY_STL_SET_H_
