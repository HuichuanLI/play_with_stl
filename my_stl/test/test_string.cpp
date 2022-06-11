//
// Created by 李汇川 on 2022/6/11.
//
#include "../string.h"
#include <iostream>
using namespace std;
int main() {
  mystring s("Hello");
  mystring s1 = s;
//  //mystring s2 = s1;
//  s1[0] = 'h'; //255
//
//  mystring s2 = s1;
  cout << "length:" << s.size() << endl;
  cout << "size:" << s.length() << endl;
  cout << "capcity:" << s.capacity() << endl;

}
