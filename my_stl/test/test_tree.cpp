//
// Created by 李汇川 on 2022/6/11.
//

#include "../tree.h"
#include "../xmemory.h"
template<class _Ty>
class KeyOfValue {
 public:
  const _Ty &operator()(const _Ty &_X) const { return _X; }
};
int main() {
//  _Tree<int, int, KeyOfValue<int>, less<int>, allocator<int> > tr(less<int>(), false);

  int ar[] = {10, 10, 10, 7, 8, 15, 5, 6, 11, 13, 12};
  int n = sizeof(ar) / sizeof(int);
  //_Tree<int, int, KeyOfValue<int>, less<int>, allocator<int> > tr(less<int>(),true);
  _Tree<int, int, KeyOfValue<int>, less<int>, myallocator<int> > tr(less<int>(), false);
  for (int i = 0; i < n; ++i)
    tr.insert(ar[i]); //

  _Tree<int, int, KeyOfValue<int>, less<int>, myallocator<int> >::iterator it = tr.begin();
//  it++;
//  it++;
//  it++;
//  it++;
//  it++;

//  cout << *it << endl;
//  tr.erase(it);

  while (it != tr.end()) {
    cout << *it << " ";
    ++it; //it++
  }
  cout << endl;
  return 0 ;
}