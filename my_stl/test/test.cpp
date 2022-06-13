//
// Created by 李汇川 on 2022/6/5.
//
#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<mybiset>
using namespace std;

int main() {
  int ar[4] = {1, 2, 3, 4};
  list<int> mylist;
  for (int i = 0; i < 4; ++i)
    mylist.push_back(ar[i]);

  list<int>::iterator it1 = mylist.begin();
  cout << *it1 << endl;
  //mylist.push_back(10);
  //cout<<*it1<<endl;
  // 插入没有问题，删除又会有问题
  //list<int>::iterator it3 = mylist.erase(it1);
  mylist.erase(it1);
  cout << *it1 << endl;
  cout << "===========================" << endl;


  //////////////////////////////////////////////
  vector<int> v;
  for (int i = 0; i < 4; ++i)
    v.push_back(ar[i]);
  vector<int>::iterator it2 = v.begin();
  cout << *it2 << endl;
  v.push_back(20);
  it2 = v.begin();
  // 向量的删除不会有问题，插入会有问题

  v.erase(it2);

  cout << *it2 << endl;
}

//void main()
//{
//	string s("Hello");
//	string s1 = s;
//
//	s1[0] = 'h';
//
//	string s2 = s1;
//	string s3 = s2;
//}

/*
void main()
{
	string s("Hello");
	string s1 = s;

	cout<<"s = "<<s<<endl;
	cout<<"s1 = "<<s1<<endl;

	s[0] = 'h';//Ð´Ê±¿½±´

	cout<<"s = "<<s<<endl;
	cout<<"s1 = "<<s1<<endl;

}

/*
void main()
{
	set<int> s;
	map<int, int> mp;
}

/*
template<class _Ty>
class KeyOfValue
{
public:
	const _Ty& operator()(const _Ty &_X)const
	{return _X;}
};

void main()
{
	int ar[] = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	int n = sizeof(ar) / sizeof(int);
	_Tree<int, int, KeyOfValue<int>, greater<int>, allocator<int> > tr(greater<int>(), false);
	for(int i=0; i<n; ++i)
		tr.insert(ar[i]); //

	_Tree<int, int, KeyOfValue<int>, greater<int>, allocator<int> >::iterator it = tr.begin();

	tr.erase(it);

	while(it != tr.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	return;
}

/*
void main()
{
	set<int> ss;
	string s;
	stack<int> st;
	queue<int> q;
}

/*
void main()
{
	deque<int> de;
	de.push_back(1);
	de.push_back(2);
	de.push_back(3);
	de.push_back(10);
	de.push_back(20);
	de.push_back(30);
	de.push_back(40);
	de.push_back(50);
	de.push_back(60);
	de.push_back(70);
	de.push_back(80);
	de.push_back(90);
	de.push_back(11);
	de.push_back(12);

	de.push_front(4);
	de.push_front(5);
	de.push_front(6);
	de.push_front(7);
	de.push_front(8);
}

/*


/*
void main()
{
	vector<int> v;
	cout<<v.capacity()<<endl;
	v.insert(v.end(), 1);
	cout<<v.capacity()<<endl;
}


/*
class String
{
public:
	String(const char *str ="")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	~String()
	{
		delete []m_data;
		m_data = NULL;
	}
private:
	char *m_data;
};

void main()
{
	list<String> mylist;
	String s("abc");

	mylist.insert(mylist.begin(), s);
}


/*
void main()
{
	list<int> mylist;
	mylist.insert(mylist.begin(), 1);
}

void main()
{
	string s("Hello");
	string s1 = s;
	s1[0] = 'h';

	string s2 = s1;//ÒýÓÃ¼ÆÊý²»Í¬£¬²»ÊÇÍ¬Ò»¸ö´æ´¢¿Õ¼ä

	string s3 = s2;

}
*/
