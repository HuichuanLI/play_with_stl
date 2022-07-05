//
// Created by lhc456 on 2022/7/6.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

int Comp(const void *e1, const void *e2) {
    return (*(int *) e2) - (*(int *) e1);
}

int Comp1(const void *e1, const void *e2) {
    return strcmp((char *) e1, (char *) e2);
}

void main() {
    int ar[] = {32, 453, 2, 3, 5, 65, 57, 67, 34, 431, 41};
    int n = sizeof(ar) / sizeof(int);

    char *br[] = {"abc", "xyz", "jflal", "nfajod", "faljd"};
    int m = sizeof(br) / sizeof(char *);

    qsort(ar, n, sizeof(int), Comp);
    qsort(br, m, sizeof(char *), Comp1);
}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	int br[10];
	int cr[10];

	copy(ar,ar+10, br);
	copy_backward(ar, ar+10, cr+10);

	int dr[] = {1,2,3,2,3,3,3,3,3,4,5,6,7,8,9,4,5,5,5,6};
	int n = sizeof(dr) / sizeof(int);
	//replace(dr, dr+n, 3, 100);

	int er[10];
	//fill(er, er+10, 2);
	fill_n(er, 4, 3);

	remove(dr, dr+n, 3);

	reverse(ar, ar+10);

	int fr[] = {32,453,2,3,5,65,57,67,34,431,41};
	n = sizeof(fr) / sizeof(int);
	//sort(fr, fr+n);
	//sort(fr, fr+n, greater<int>());

	qsort(fr, n, sizeof(int),

}

/*
/*
template<class _II, class _Ty>
_II find(_II _F, _II _L, const _Ty& _V)
{
	for (; _F != _L; ++_F)
		if (*_F == _V)
			break;
	return (_F);
}


void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10}; //1 4 9 .....100
	vector<int> v(ar, ar+10);
	list<int> mylist(ar, ar+10);

	int *pos = find(ar, ar+10, 0);
	if(pos == ar+10)
		cout<<"Find Error."<<endl;
	else
		cout<<*pos<<endl;

	vector<int>::iterator it = find(v.begin(), v.end(), 40);
	if(it == v.end())
		cout<<"Find vector Error."<<endl;
	else
		cout<<*it<<endl;

	int br[10] = {1,2,3,4,3,3,3,4,5,6};
	cout<<count(br, br+10, 3)<<endl;
}

/*
void NumPow(int n)
{
	cout<<n*n<<" ";
}

void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10}; //1 4 9 .....100

	vector<int> v(ar, ar+10);

	vector<int>::iterator first = v.begin();
	vector<int>::iterator last = v.end();

	list<int> mylist(ar, ar+10);

	//for_each(first, last, NumPow);
	for_each(mylist.begin(), mylist.end(), NumPow);
	cout<<endl;
}

/*
template<class _II, class _Fn>
_Fn for_each(_II _F, _II _L, _Fn _Op)
{
	for (; _F != _L; ++_F)
		_Op(*_F);
	return (_Op);
}



void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10}; //1 4 9 .....100
	for(int i=0; i<10; ++i)
	{
		cout<<ar[i] * ar[i]<<" ";
	}
	cout<<endl;

	for_each(ar, ar+10, NumPow);
	cout<<endl;

}
*/