#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void main() {
    stack<int> st;
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);

    /*
    int value = Q.front();
    Q.pop();
    cout<<value<<" pop queue."<<endl;

    cout<<"size : "<<Q.size()<<endl;
    */
    int value;
    while (!Q.empty()) {
        value = Q.front();
        cout << value << " pop queue." << endl;
        Q.pop();
    }
}

/*
void main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);

	
	int value = st.top();
	st.pop();
	cout<<value<<" pop stack."<<endl;
	cout<<"size : "<<st.size()<<endl;
	
	
	int value;
	while(!st.empty())
	{
		value = st.top();
		cout<<value <<" pop statck."<<endl;
		st.pop();
	}
	
}
*/