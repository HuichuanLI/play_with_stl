//
// Created by lhc456 on 2022/7/6.
//
#include<iostream>
#include<deque>

using namespace std;

void main() {
    //deque<int> d(10, 1);
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    //4  3  1  2
    //   p

    deque<int>::iterator p = d.begin();
    p++;
    //d.resize(10);
    //cout<<d.front()<<endl;
    //cout<<d.back()<<endl;

    d.insert(p, 10, 100);

    for (int i = 0; i < d.size(); ++i)
        //cout<<d[i]<<" ";
        cout << d.at(i) << " ";
    cout << endl;

    deque<int>::iterator it = d.begin();
    while (it != d.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}