#pragma once

//class�� ���� ������ ������ְų� �����ϱ� ���� ���

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