//
// Created by 李汇川 on 2022/6/4.
//
#include "list.h"
#include <iostream>
using namespace std;
int main() {
  list<int> mylist;
  int arr[5] = {1, 2, 3, 4, 5};
//  for (int i = 0; i < 5; i++) {
//    mylist.push_back(i);
//  }
//
//  list<int>::iterator it = mylist.begin();
//  while (it != mylist.end()) {
//    cout << *it << " ";
//    ++it;
//  }
//  cout << endl;

  mylist.insert(mylist.end(), 10, 2);
  list<int>::iterator it = mylist.begin();
  while (it != mylist.end()) {
    cout << *it << " ";
    it++; //it++
  }
  mylist.insert(mylist.end(), arr, arr + 5);
  it = mylist.begin();
  while (it != mylist.end()) {
    cout << *it << " ";
    it++; //it++
  }

  //list<int> youlist(10, 1);

}