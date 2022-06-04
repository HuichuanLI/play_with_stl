//
// Created by 李汇川 on 2022/6/4.
//
#include "list.h"
#include <iostream>
using namespace std;
int main() {
  list<int> mylist;
  int arr[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    mylist.push_back(i);
  }
}