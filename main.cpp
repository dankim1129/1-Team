#include "interface.h"
#include "util.h"
#include "game.h"
#include "score.h"

// class h ���� : �ֱ� �������� ����
highscore h = highscore();

int main() {

	int menu_num;
	
	while (1) {
		Init();
		StartDraw();
		Update(h.name, h.score);
		menu_num = MenuDraw();

		if (menu_num == 0) {// ���ӽ��� ��ư�� �������� 
			GameStart();
		}
		else if (menu_num == 1) // ���� ���
			ScorePrint();
		else if(menu_num == 2) // �� ��
			break;
	}

	return 0;
}
