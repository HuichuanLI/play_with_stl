//
// Created by 李汇川 on 2022/6/11.
//

#include "../deque.h"
#include "../stack.h"
#include "../queue.h"
#include "../vector.h"
#include "../list.h"


int main() {
  stack<int > st;
  st.push(1);
  st.pop();

  queue<int, Vector<int> > q;
  q.push(1);
//  q.pop();

  queue<int, list<int> > Q;
  Q.push(1);
  Q.pop();
}