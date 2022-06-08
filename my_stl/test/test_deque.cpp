//
// Created by 李汇川 on 2022/6/9.
//
#include "../deque.h"

int main() {
  deque<int> de;
  de.push_back(1);
  de.push_back(2);
  de.push_back(3);
  de.push_back(10);
  de.push_back(20);
  de.push_back(30);
  de.push_back(40);
  de.push_back(50);
  de.push_back(60);
  de.push_back(70);
  de.push_back(80);
  de.push_back(90);
  de.push_back(11);
  de.push_back(12);

  de.push_front(4);
  de.push_front(5);
  de.push_front(6);
  de.push_front(7);
  de.push_front(8);

  deque<int>::iterator it = de.begin();

  //cout<<it[2]<<endl;
  //it += 5;
  //cout<<*it<<endl;
  while (it != de.end()) {
    cout << *it << " "; //it->
    ++it; //it++  --it it--
  }
  cout << endl;
}