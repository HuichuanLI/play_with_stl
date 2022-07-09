//
// Created by lhc456 on 2022/7/9.
//
#include<iostream>
#include<bitset>
#include<string>

using namespace std;

void main() {
    bitset<10> bt("0000001010");
    bitset<10> bt1("1010000111");
    //cout<<bt<<endl;
    //bt >>= 2;
    //bt <<= 2;
    //cout<<bt<<endl;

    cout << bt << endl;
    //bt ^= bt1;
    bt = ~bt;
    cout << bt << endl;

}

/*
void main()
{
	int a = 10; //1010
	a = ~a;  //   0101  == 5
	cout<<a<<endl; // -11  ??????????
}

void main()
{
	bitset<12> bt(1234);
	//bitset<20> bt("1000101010");
	cout<<bt<<endl;
	cout<<bt.to_ulong()<<endl;
	cout<<bt.to_string()<<endl; // "1010110"
}

/*
void main()
{
	bitset<10> bt;
	bt.set(2);
	cout<<bt<<endl;
	cout<<bt.none()<<endl;
	cout<<bt.any()<<endl;
	cout<<bt.test(2)<<endl;
}

/*
void main()
{
	bitset<10> bt;
	//bt[9] = 1;
	bt.set(4);  //
	cout<<bt<<endl;
	bt.flip();
	//bt.reset();
	cout<<bt<<endl;
	cout<<"size = "<<bt.size()<<endl;
	cout<<"count = "<<bt.count()<<endl;
}
*/