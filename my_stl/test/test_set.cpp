//
// Created by lhc456 on 2022/7/10.
//
#include<iostream>
#include<set>

using namespace std;

int main() {
    int ar[] = {15, 12, 45, 53, 21, 67, 85, 79, 90, 7};
    set<int> s;
    for (int i = 0; i < sizeof(ar) / sizeof(int); ++i) {
        s.insert(ar[i]);
    }

    set<int>::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << *s.lower_bound(21) << endl;
    cout << *s.upper_bound(21) << endl;

    pair<set<int>::iterator, set<int>::iterator> pa = s.equal_range(21); //low  high
    cout << "low : " << *pa.first << endl;
    cout << "high : " << *pa.second << endl;
//    cout<<*(s.equal_range(21))<<endl; //low  high
    return 0;
}

//class Student;
//ostream& operator<<(ostream &out, const Student &s);
//
//class Student
//{
//    friend ostream& operator<<(ostream &out, const Student &s);
//public:
//    Student(char *n, int a) : age(a)
//    {
//        strcpy(name, n);
//    }
//public:
//    bool operator<(const Student &s)const
//    {
//        return age < s.age;
//    }
//public:
//    void ShowStu()const
//    {
//        cout<<"name : "<<name<<" , age : "<<age<<endl;
//    }
//private:
//    char name[10];
//    int age;
//};
//
//ostream& operator<<(ostream &out, const Student &s)
//{
//    out<<"name : "<<s.name<<" , age : "<<s.age;
//    return out;
//}

//int main() {
//    int ar[] = {15, 12, 45, 53, 21, 67, 85, 79, 90, 7, 15, 15, 15, 15};
//    set<int> s;
//    for (int i = 0; i < sizeof(ar) / sizeof(int); ++i) {
//        s.insert(ar[i]);
//    }
//
//    set<int>::iterator it = s.begin();
//    while (it != s.end()) {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//    cout << "size = " << s.size() << endl;
//    cout << "count = " << s.count(150) << endl;
//    return 0;
//}


//void main() {
//    int ar[] = {15, 12, 45, 53, 21, 67, 85, 79, 90, 7, 15, 15, 15, 15};
//    set<int> s;
//    for (int i = 0; i < sizeof(ar) / sizeof(int); ++i) {
//        s.insert(ar[i]);
//    }
//
//    set<int>::iterator it = s.begin();
//    while (it != s.end()) {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//    cout << "size = " << s.size() << endl;
//    cout << "count = " << s.count(150) << endl;
//}