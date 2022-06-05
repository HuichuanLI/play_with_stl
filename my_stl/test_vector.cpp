//
// Created by 李汇川 on 2022/6/4.
//
#include "vector.h"
//
//int main() {
//  Vector<int> v;
//  v.insert(v.end(), 1, 1);
//  v.insert(v.end(), 1, 2);
//  v.insert(v.end(), 1, 3);
//  v.insert(v.end(), 1, 4);
//}

int main() {
  Vector<int> v;
  for (int i = 1; i <= 10; ++i)
    v.push_back(i);
  cout << "capacity = " << v.capacity() << endl;

  //v.pop_back();
//  v.clear();

  for (int i = 0; i < v.size(); ++i)
    //cout<<v.at(i)<<" ";
    cout << v[i] << " ";
  cout << endl;

  cout << "front = " << v.front() << endl;
  cout << "back = " << v.back() << endl;

}
/*
vector<int>::iterator it = v.begin();
while(it != v.end())
{
    cout<<*it<<" ";
    ++it;
}
cout<<endl;
}*/