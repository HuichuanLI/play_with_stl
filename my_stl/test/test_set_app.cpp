//
// Created by lhc456 on 2022/7/10.
//
#include <set>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    Student(string no, string name) : m_strNo(no), m_strName(name) {}

    ~Student() {}

public:
    bool operator<(const Student &s) const {
        return m_strNo < s.m_strNo;
    }

public:
    void ShowStud() const {
        cout << m_strNo << "\t" << m_strName << endl;
    }

private:
    string m_strNo;
    string m_strName;
};

template<class Ty>
class Myset : public set<Ty> {
public:
    Myset(Ty *first, Ty *last) : set<Ty>(first, last) {}

public:
    void UnionSet(Myset<Ty> &s) {
        auto it = s.begin();
        while (it != s.end()) {
            this->insert(*it);
            ++it;
        }
    }

    void IntersectionSet(Myset<Ty> &s) {
        set<Ty> tmp;
        auto it = this->begin();
        while (it != this->end()) {
            if (s.find(*it) != s.end())
                tmp.insert(*it);
            ++it;
        }
        swap(tmp);
    }

    void DifferenceSet(Myset<Ty> &s) {
        set<Ty> tmp;
        auto it = this->begin();
        while (it != this->end()) {
            if (s.find(*it) == s.end())
                tmp.insert(*it);
            ++it;
        }
        this->swap(tmp);
    }

public:
    void Show() const {
        auto it = this->begin();
        while (it != this->end()) {
            it->ShowStud();
            ++it;
        }
    }
};

int main() {
    Student stud1[] = {
            Student("1001", "bss"),
            Student("1002", "liyan"),
            Student("1008", "Cpp")
    };
    Student stud2[] = {
            Student("1001", "bss"),
            Student("1002", "liyan"),
            Student("1003", "Hello"),
            Student("1004", "Linux")
    };
    Myset<Student> s1(stud1, stud1 + 3);
    Myset<Student> s2(stud2, stud2 + 4);

    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7, 8, 9};
    Myset<int> s3(arr, arr + 5);
    Myset<int> s4(arr2, arr2 + 5);


    //s1.UnionSet(s2);
    //s1.IntersectionSet(s2);
    //s1.DifferenceSet(s2);
    s3.DifferenceSet(s4);
    s2.Show();


}