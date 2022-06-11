//
// Created by 李汇川 on 2022/6/11.
//

#include "../tree.h"

template<class _Ty>
class KeyOfValue {
 public:
  const _Ty &operator()(const _Ty &_X) const { return _X; }
};
int main() {
  _Tree<int, int, KeyOfValue<int>, less < int>, allocator < int > > tr(less<int>(), false);
}