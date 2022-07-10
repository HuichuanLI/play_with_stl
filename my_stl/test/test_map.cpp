#include<iostream>
#include<map>
#include<string>

using namespace std;

//map<key-value>

int main() {
    map<string, string> mp;
    mp["1-1"] = "元旦节";
    mp["10-1"] = "国庆节";

    mp["1-1"] = "jflafjalkfa";

    map<string, string>::iterator it = mp.begin();
    while (it != mp.end()) {
        cout << (*it).first << ":" << (*it).second << endl;
        ++it;
    }
}

/*
void main()
{
	map<int, string> mp;
	pair<int, string> p1(1, "abc");
	pair<int, string> p2(2, "xyz");
	pair<int, string> p3(3, "lmn");
	pair<int, string> p4(4, "abc");
	pair<int, string> p5(5, "hjk");

	mp.insert(p4);
	mp.insert(p1);
	mp.insert(p5);
	mp.insert(p2);
	mp.insert(p3);

	map<int, string>::iterator it = mp.begin();
	while(it != mp.end())
	{
		cout<<(*it).first<<":"<<(*it).second<<endl;
		++it;
	}
	cout<<"size : "<<mp.size()<<endl;
	cout<<"count : "<<mp.count(2)<<endl; //0  1

	cout<<(*mp.lower_bound(3)).first<<" : "<<(*mp.lower_bound(3)).second<<endl;
	cout<<(*mp.upper_bound(3)).first<<" : "<<(*mp.upper_bound(3)).second<<endl;
}
//
///*
//void main()
//{
//	multimap<int, string> mp;
//	pair<int, string> p1(1, "abc");
//	pair<int, string> p2(2, "xyz");
//	pair<int, string> p3(3, "lmn");
//	pair<int, string> p4(4, "abc");
//	pair<int, string> p5(5, "hjk");
//	pair<int, string> p6(2, "opq");
//
//	mp.insert(p1);
//	mp.insert(p5);
//	mp.insert(p2);
//	mp.insert(p3);
//	mp.insert(p4);
//
//	mp.insert(p6);
//
//	multimap<int, string>::iterator it = mp.begin();
//	while(it != mp.end())
//	{
//		cout<<(*it).first<<":"<<(*it).second<<endl;
//		++it;
//	}
//}
//
///*
int  main()
{
	map<int, string> mp;
	pair<int, string> p1(1, "abc");
	pair<int, string> p2(2, "xyz");
	pair<int, string> p3(3, "lmn");
	pair<int, string> p4(4, "abc");
	pair<int, string> p5(5, "hjk");
	pair<int, string> p6(2, "opq");

	mp.insert(p1);
	mp.insert(p5);
	mp.insert(p2);
	mp.insert(p3);
	mp.insert(p4);

	mp.insert(p6);

	map<int, string>::iterator it = mp.begin();
	while(it != mp.end())
	{
		cout<<(*it).first<<":"<<(*it).second<<endl;
		++it;
	}
}
 */
//int main()
//{
//	map<int, string> mp;
//	pair<int, string> p1(1, "abc");
//	pair<int, string> p2(2, "xyz");
//	pair<int, string> p3(3, "lmn");
//	pair<int, string> p4(4, "abc");
//	pair<int, string> p5(5, "hjk");
//
//	mp.insert(p4);
//	mp.insert(p1);
//	mp.insert(p5);
//	mp.insert(p2);
//	mp.insert(p3);
//
//	map<int, string>::iterator it = mp.begin();
//	while(it != mp.end())
//	{
//		cout<<(*it).first<<":"<<(*it).second<<endl;
//		++it;
//	}
//	cout<<"size : "<<mp.size()<<endl;
//	cout<<"count : "<<mp.count(2)<<endl; //0  1
//
//	cout<<(*mp.lower_bound(3)).first<<" : "<<(*mp.lower_bound(3)).second<<endl;
//	cout<<(*mp.upper_bound(3)).first<<" : "<<(*mp.upper_bound(3)).second<<endl;
//}