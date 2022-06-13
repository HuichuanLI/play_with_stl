//
// Created by 李汇川 on 2022/6/13.
//

#include<iostream>

#include "../biset.h"
using namespace std;

int main() {
  mybiset<10> bt;
  bt.set(3);
  cout << bt << endl;
  cout << bt.at(3) << endl;
  cout << bt[3] << endl;

  bt[2] = 1;
  cout << bt << endl;
  //bt[2].flip();
  ~bt[2];
  cout << bt << endl;
  return 0;
}