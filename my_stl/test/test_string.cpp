//
// Created by lhc456 on 2022/7/9.
//
#include<iostream>
#include<string>

using namespace std;

//strcmp(s1, s2);
//s1 == s2   0
//s1 >  s2   1
//s1 <  s2   -1

void main() {
    string str = "abcxyz";
    string str1 = "afxfb";

    //cout<<str.find_first_of(str1)<<endl;
    //cout<<str.find_first_not_of(str1)<<endl;
    cout << str.find_last_of(str1) << endl;
}

/*
void main()
{
	//char *
	//string str = "Hello";
	string str("Hello");
	string str1 = "This is String.";
	string str2 = "hello";

	string s = "This@ is String Test@163.com";
	s.replace(s.find('@'), 1, "");
	cout<<"s = "<<s<<endl;
	//cout<<str.rfind('e')<<endl;
	//cout<<str.replace(1, 3, "abc")<<endl;

	//cout<<str.data()<<endl;
	//cout<<str.compare(str2)<<endl;

	//str.resize(200);
	//str.reserve(200);
	//str.assign(str1);

	//cout<<str.at(0)<<endl;
	//str[0] = 'h';
	//cout<<str[0]<<endl;
	//str += "World"; //HelloWorld
	//str += str1;
	//str.append(str1);
	//str = str1;
	//str.insert(3, "abcxyz");
	//str.erase(2,2);
	//str.swap(str1);

	//char str3[] = "abcxyz";
	//str.copy(str3 , 2, 1);
	                      //a b c x y z
	                      //H e l l o
	//cout<<"str3 = "<<str3<<endl;

	//const char *s = str.c_str();
	//cout<<s<<endl;

	//cout<<"str1 substr = "<<str1.substr(5,2)<<endl;

	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
}

/*
void main()
{
	string str = "Hello";
	cout<<"str = "<<str<<endl;

	string::iterator it = str.begin();
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;
	string::reverse_iterator rit = str.rbegin();
	while(rit != str.rend())
	{
		cout<<*rit;
		++rit;
	}
	cout<<endl;
}
*/