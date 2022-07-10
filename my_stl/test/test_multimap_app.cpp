//
// Created by lhc456 on 2022/7/10.
//
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class CWord {
public:
    CWord(string strLine) {
        istringstream in(strLine);
        in >> mainword;

        string tmp;
        while (!in.eof()) {
            in >> tmp;
            vecword.push_back(tmp);
        }
    }

public:
    string GetMainWord() { return mainword; }

public:
    void ShowWord() const {
        cout << "单词是:" << "\t" << mainword << endl;
        cout << "同义词是:>" << "\t";
        for (int i = 0; i < vecword.size(); ++i)
            cout << vecword[i] << "\t";
        cout << endl;

    }

private:
    string mainword;//主单词
    vector<string> vecword; //同义词
};

class CWordManage {
public:
    void AddWordInfo(string strLine) {
        CWord word(strLine);
        pair<string, CWord> pr(word.GetMainWord(), word);
        wordmap.insert(pr);
    }

public:
    void ShowAllWord() const {
        multimap<string, CWord>::const_iterator it = wordmap.begin();
        while (it != wordmap.end()) {
            const CWord &obj = (*it).second;
            obj.ShowWord();
            ++it;
        }
    }

public:
    void FindWord(string w) const {
        multimap<string, CWord>::const_iterator it = wordmap.begin();
        while (it != wordmap.end()) {
            if (w == (*it).first) {
                const CWord &obj = (*it).second;
                obj.ShowWord();
                break;
            }
            ++it;
        }
        if (it == wordmap.end())
            cout << "要查询的单词没有同义词." << endl;
    }

private:
    multimap<string, CWord> wordmap;
};

int main() {
    string str[] = {
            string("one  unique  single"), //key-value
            string("corrent  true  right"),
            string("near  close"),
            string("happy   please"),
            string("strong   powerful")
    };

    CWordManage cwm;
    for (int i = 0; i < 5; ++i)
        cwm.AddWordInfo(str[i]);

    //cwm.ShowAllWord();
    cwm.FindWord("strong");
    return 0;
}
