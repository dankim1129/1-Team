#include "interface.h"
#include "util.h"
#include "game.h"
#include "score.h"

// class h 선언 : 최근 게임점수 저장
highscore h = highscore();

int main() {

	int menu_num;
	
	while (1) {
		Init();
		StartDraw();
		Update(h.name, h.score);
		menu_num = MenuDraw();

		if (menu_num == 0) {// 게임시작 버튼이 눌렸으면 
			GameStart();
		}
		else if (menu_num == 1) // 점수 출력
			ScorePrint();
		else if(menu_num == 2) // 종 료
			break;
	}

	return 0;
}
