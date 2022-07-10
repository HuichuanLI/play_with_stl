//
// Created by lhc456 on 2022/7/10.
//

#include <iostream>
#include <algorithm>
#include<functional>
#include <vector>

using namespace std;

int Sum(int a, int b) {
    return a + b;
}

/*
template<class _Ty>
struct plus : binary_function<_Ty, _Ty, _Ty>
{
	_Ty operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X + _Y); }
};
*/

int main() {

    int ar[4] = {3, 5, 1, 2};
    vector<int> v(ar, ar + 4);

    //sort(v.begin(), v.end(), greater<int>()); //  _P()
    sort(v.begin(), v.end(), less<int>());

    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    cout << Sum(10, 20) << endl;
    plus<int> ps;
    cout << ps(10, 20) << endl;  //·Âº¯Êý  ps(10,20)==> ps.operator()(10,20)
    return 0;
}