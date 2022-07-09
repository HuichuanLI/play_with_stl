//
// Created by lhc456 on 2022/7/9.
//
#include <iostream>
#include <stack>

using namespace std;

template<class _Ty>
class mystack : public stack<_Ty> {
public:
    mystack(int sz) : m_iMaxsize(sz) {}

    ~mystack() {}

public:
    void push(const _Ty &v) {
        if (this->size() < m_iMaxsize)
            stack<_Ty>::push(v);
        else
            cout << "stack full, not push." << endl;
    }

private:
    int m_iMaxsize;
};

int main() {
    mystack<int> st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    return 0;

}