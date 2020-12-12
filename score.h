#pragma once

//class와 현재 순위를 출력해주거나 저장하기 위한 헤더

class highscore {
public:
	string name;
	int score;
	highscore();
	highscore(char* name_, int score_);
	~highscore() {}
};


void ScorePrint();
void Update(string , int);