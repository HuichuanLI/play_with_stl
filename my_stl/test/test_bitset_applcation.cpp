//
// Created by lhc456 on 2022/7/9.
//
#include<bitset>
#include<string>
#include <iostream>
#include <vector>

using namespace std;

template<size_t N>
class Attend {
public:
    Attend(int month, string attend) : m_month(month), bt(attend) {}

    ~Attend() {}

public:
    int GetMonth() const { return m_month; }

    int GetAttendDays() const { return bt.count(); }

private:
    int m_month;
    bitset<N> bt; //1010101010101101010101010
};

class Student {
public:
    Student(string name) : m_strName(name) {}

public:
    void AddAttendInfo(Attend<31> &ad) {
        v.push_back(ad);
    }

    void ShowAttendInfo() const {
        cout << "姓名:" << m_strName << endl;
        cout << "月份" << "\t" << "出勤天数" << endl;
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i].GetMonth() << "\t" << v[i].GetAttendDays() << endl;
        }
    }

private:
    string m_strName;
    vector<Attend<31> > v;
};

int main() {

    string info1 = "1101111101111100111111101111111";
    string info2 = "1111011111110111111101110111";
    string info3 = "1111111101111110111111101111111";

    Attend<31> ad1(1, info1);
    Attend<31> ad2(2, info2);
    Attend<31> ad3(3, info3);

    Student s("bss");  //Student s1("abc");
    s.AddAttendInfo(ad1);
    s.AddAttendInfo(ad2);
    s.AddAttendInfo(ad3);

    s.ShowAttendInfo();

    return 0;

}
