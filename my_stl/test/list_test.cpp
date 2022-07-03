//
// Created by lhc456 on 2022/7/3.
//
#include<iostream>
#include<list>

using namespace std;

// 1  2  3  4  5
//    it
// 1  100  2  3  4
//         it

int main() {                              //it
    int ar1[] = {1, 2, 3, 4, 5};   //1  2  3  4  5  6  7  8  9  10
    int ar2[] = {6, 7, 8, 9, 10};  //
    list<int> mylist(ar1, ar1 + 5);
    list<int> youlist(ar2, ar2 + 5);

    //list<int>::iterator it = mylist.begin();
    //mylist.splice(it, youlist);

    mylist.merge(youlist);

    list<int>::iterator it = mylist.begin();
    while (it != mylist.end()) {
        cout << *it << " ";
        ++it; //it++
    }
    cout << endl;

    it = youlist.begin();
    while (it != youlist.end()) {
        cout << *it << " ";
        ++it; //it++
    }
    cout << endl;
    return 0;
}

/*
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(2);
	mylist.push_back(2);
	mylist.push_back(2);
	mylist.push_back(4);

	//mylist.sort();//??????
	mylist.remove(2);

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

}

/*
void main()
{
	int ar1[] = {1,2,3,4,5};
	int ar2[] = {6,7,8,9,10};
	list<int> mylist(ar1, ar1+5);
	list<int> youlist(ar2, ar2+5);

	//mylist.swap(youlist);
	mylist.reverse();

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

	it = youlist.begin();
	while(it != youlist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;
}

/*
void main()
{
	list<int> mylist;

	for(int i=1; i<=5; ++i)
	{
		mylist.push_back(i);
	}

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

	it = mylist.begin();
	it++;
	mylist.insert(it, 100);

	list<int>::iterator f = mylist.begin();
	list<int>::iterator l = mylist.end();
	mylist.erase(f,l);

	it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;


}

/*
void main()
{
	int ar[] = {10,20,30,40,50};
	list<int> mylist;
	list<int> youlist(ar, ar+5);
	list<int>::iterator first = youlist.begin();
	list<int>::iterator last = youlist.end();

	for(int i=1; i<=10; ++i)
	{
		mylist.push_back(i);
	}

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

	mylist.assign(first, last);
	it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;


}

/*
void main()
{
	list<int> mylist;


	for(int i=1; i<=10; ++i)
	{
		mylist.push_back(i);
	}

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

	mylist.assign(5,1);

	cout<<"size : "<<mylist.size()<<endl;
	cout<<"max size : "<<mylist.max_size()<<endl;
	cout<<"is empty :"<<mylist.empty()<<endl;

	int value = mylist.front();
	value = mylist.back();

	it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;
}

/*
void main()
{
	list<int> mylist;
	for(int i=1; i<=10; ++i)
	{
		mylist.push_back(i);
	}

	//����
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;

	list<int>::reverse_iterator rit = mylist.rbegin();
	while(rit != mylist.rend())
	{
		cout<<*rit<<" ";
		rit++;
	}
	cout<<endl;
}

/*
int main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_front(3);
	mylist.push_front(4);

	//4 3 1 2
	mylist.pop_back();
	//4 3 1
	mylist.pop_front();

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over"<<endl;

	return 0;
}

/*

int main()
{
	//list<int> mylist;
	//list<int> mylist(10);
	//list<int> mylist(10, 2);
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	list<int> mylist(ar, ar+10);

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over"<<endl;

	return 0;
}
*/