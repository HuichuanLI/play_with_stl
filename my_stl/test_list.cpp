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

  list<int>::iterator it = mylist.begin();
  while (it != mylist.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;

  mylist.insert(mylist.end(), 10, 2);
  it = mylist.begin();
  while (it != mylist.end()) {
    cout << *it << " ";
    it++; //it++
  }
  mylist.clear();
  cout << endl;
  mylist.insert(mylist.end(), arr, arr + 5);
  it = mylist.begin();
  while (it != mylist.end()) {
    cout << *it << " ";
    it++; //it++
  }
  cout << mylist.front() << endl;
  cout << mylist.back() << endl;

}

//
//class String {
// public:
//  String(const char *str = "") {
//    m_data = new char[strlen(str) + 1];
//    strcpy(m_data, str);
//  }
//  ~String() {
//    delete[]m_data;
//    m_data = NULL;
//  }
// private:
//  char *m_data;
//};
//
//int main() {
//  list<String> mylist;
//  String s("abc");
//
//  mylist.insert(mylist.begin(), s);
//}
