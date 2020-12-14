#define _CRT_SECURE_NO_WARNINGS

#include "util.h"
#include "score.h"
#include <map>
#include <fstream>

using namespace std;


highscore::highscore() {
    score = 0;
}
highscore::highscore(char* name_, int score_) {
    name = name_;
    score = score_;
}

//map 사용으로 rankdata에 정보를 불러와 현재 순위 나열
map<int, string, greater<int>> rankdata;

void ScorePrint() {

    system("cls");
    map<int, string>::iterator iter;
    int i = 1;
    for (iter = rankdata.begin(); iter != rankdata.end(); iter++) {
        cout << i << "등\tname : " << iter->second << "\tscore : " << iter->first << endl;
        i++;
        if (i == 11)
            break;
    }
    system("pause");
}

void Update(string name_, int score_) {

    //input.txt에서 등수 불러오기
    ifstream fin("input.txt", ios_base::in);

    rankdata.clear();
    for (int i = 0; i < 10; i++) {

        string tempname; int tempscore;
        fin >> tempname;
        fin >> tempscore;
        rankdata.insert(pair<int,string>(tempscore,tempname));
    }
    fin.close();


    if (score_ != 0)
        rankdata.insert(pair<int, string>(score_,name_));

    //input.txt에 등수 저장하기
    ofstream fout("input.txt", ios_base::out);
    int i = 1;
    map<int, string>::iterator iter;
    for (iter = rankdata.begin(); iter != rankdata.end(); iter++) {
        fout << iter->second << " " << iter->first << endl;
        i++;
        if (i == 11)
            break;
    }
    fout.close();
}