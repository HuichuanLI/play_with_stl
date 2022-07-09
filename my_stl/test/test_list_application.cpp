//
// Created by lhc456 on 2022/7/9.

#include<iostream>
#include<vector>
#include<string>
#include<list>
//
using namespace std;

class Student {
    friend class StudManger;
public:
    Student(string no, string name, string sex, string date)
            : m_strNo(no), m_strName(name), m_strSex(sex), m_strDate(date) {}

    ~Student() {}

public:
    bool operator<(Student &s) {
        return m_strNo < s.m_strNo;
    }

    bool operator==(Student &s) {
        return m_strNo == s.m_strNo;
    }

public:
    void ShowStud() const {
        cout << m_strNo << "  " << m_strName << "  " << m_strSex << "  " << m_strDate << endl;
    }

private:
    string m_strNo;
    string m_strName;
    string m_strSex;
    string m_strDate;
};

class StudManger {
public:
    void AddInfo(Student &s) {
        m_lStud.push_back(s);
    }

    void ShowInfo() const {
        list<Student>::const_iterator it = m_lStud.begin();
        while (it != m_lStud.end()) {
            it->ShowStud();
            ++it;
        }
    }

    void MergeInfo(StudManger &sm) {
        m_lStud.sort();
        sm.m_lStud.sort();
        m_lStud.merge(sm.m_lStud);
        m_lStud.unique();
    }

private:
    list<Student> m_lStud;
};

int main() {
    Student s1("1001", "解放路", "男", "1988-08-08");
    Student s2("1002", "放假啦", "女", "1980-09-08");
    Student s3("1003", "就离间", "男", "1990-10-10");
    Student s4("1004", "鱼哦发", "女", "1999-11-11");
    Student s5("1005", "韩剧式", "男", "1992-03-02");

    StudManger sm1, sm2;   //
    sm1.AddInfo(s1);
    sm1.AddInfo(s3);
    sm1.AddInfo(s5);
    sm1.AddInfo(s2);

    sm2.AddInfo(s2);
    sm2.AddInfo(s4);
    sm2.AddInfo(s3);
    sm2.AddInfo(s5);

    sm1.MergeInfo(sm2);

    sm1.ShowInfo();
    cout << endl;
    sm2.ShowInfo();
    return 0;
}


//class StudManger;
//
//class Student {
//    friend class StudManger;
//
//public:
//    Student(string no, string name, string sex, string date)
//            : m_strNo(no), m_strName(name), m_strSex(sex), m_strDate(date) {}
//
//    ~Student() {}
//
//public:
//    void ShowStud() const {
//        cout << m_strNo << "  " << m_strName << "  " << m_strSex << "  " << m_strDate << endl;
//    }
//
//private:
//    string m_strNo;
//    string m_strName;
//    string m_strSex;
//    string m_strDate;
//};
//
//class StudManger {
//public:
//    void AddStud(Student &s) {
//        m_vStud.push_back(s);
//    }
//
//    Student *FindStud(string no) {
//        for (int i = 0; i < m_vStud.size(); ++i) {
//            if (m_vStud[i].m_strNo == no)
//                return &m_vStud[i];
//        }
//        return NULL;
//    }
//
//    void ShowAllStud() const {
//        for (int i = 0; i < m_vStud.size(); ++i) {
//            m_vStud[i].ShowStud();
//        }
//    }
//
//private:
//    vector<Student> m_vStud;
//};

void main() {
    StudManger sm;
    string no, name, sex, date;
    int select = 1;
    while (select) {
        cout << "********************************************" << endl;
        cout << "* [1] 增加学生信息    [2] 显示所有学生信息 *" << endl;
        cout << "* [3] 查询学生        [0] 退出系统         *" << endl;
        cout << "********************************************" << endl;
        cout << "请选择:>";
        cin >> select;

        if (select == 1) {
            cout << "请输入学生信息:>";
            cin >> no >> name >> sex >> date;
            Student s(no, name, sex, date);
            sm.AddStud(s);
        } else if (select == 2) {
            sm.ShowAllStud();
        } else if (select == 3) {
            cout << "请输入要查询的学号:>";
            cin >> no;
            Student *ps = sm.FindStud(no);
            if (ps != NULL)
                ps->ShowStud();
            else
                cout << "查无此人." << endl;
        } else if (select == 0)
            break;
    }
}

/*
void main()
{
	Student s1("1001", "解放路", "男", "1988-08-08");
	Student s2("1002", "放假啦", "女", "1980-09-08");
	Student s3("1003", "就离间", "男", "1990-10-10");
	Student s4("1004", "鱼哦发", "女", "1999-11-11");
	Student s5("1005", "韩剧式", "男", "1992-03-02");

	StudManger sm;
	sm.AddStud(s1);
	sm.AddStud(s2);
	sm.AddStud(s3);
	sm.AddStud(s4);
	sm.AddStud(s5);

	sm.ShowAllStud();

	cout<<endl;
	Student *ps = sm.FindStud("10002");
	if(ps != NULL)
		ps->ShowStud();
	else
		cout<<"查无此人."<<endl;

}
*/

