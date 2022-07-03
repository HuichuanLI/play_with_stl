//
// Created by lhc456 on 2022/7/4.
//
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int ar[] = {1, 2, 3, 4, 5};
    vector<int> v(ar, ar + 5);

    //vector<int>::iterator it = v.end();
    //it--;
    //it++;
    //v.insert(it, 10,8);
    //v.erase(it);
    v.assign(10, 100);

    for (int i = 0; i < v.size(); ++i) {
        //cout<<v[i]<<" ";
        cout << v.at(i) << " ";
    }
    cout << endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(ar, ar+10);

	//v.reserve(50);
	//v.push_back(11);
	v.resize(5);
	cout<<v.capacity()<<endl;
	cout<<v.size()<<endl;

	for(int i=0; i<v.size(); ++i)
	{
		//cout<<v[i]<<" ";
		cout<<v.at(i)<<" ";
	}
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(ar, ar+10);

	//v.clear();
	//v[3] = 100;
	//cout<<v.front()<<endl;
	//cout<<v.back()<<endl;
	//v.pop_back();

	for(int i=0; i<v.size(); ++i)
	{
		//cout<<v[i]<<" ";
		cout<<v.at(i)<<" ";
	}
	cout<<endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	while(rit != v.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(ar, ar+10);

	for(int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;

	vector<int>::iterator it = v.begin();
	while(it != v.end())
	{
		cout<<*it<<" ";
		++it; //it++ // ??????
	}
	cout<<endl;
}

/*
void main()
{
	vector<int> v;
	cout<<"capacity : "<<v.capacity()<<endl;
	v.push_back(1);
	cout<<"capacity : "<<v.capacity()<<endl;
	v.push_back(2);
	cout<<"capacity : "<<v.capacity()<<endl;
	v.push_back(3);
	cout<<"capacity : "<<v.capacity()<<endl;
	v.push_back(4);
	cout<<"capacity : "<<v.capacity()<<endl;
	v.push_back(5);
	cout<<"capacity : "<<v.capacity()<<endl;

}
*/