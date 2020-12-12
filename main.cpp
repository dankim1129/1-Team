#include "interface.h"
#include "util.h"
#include "game.h"
int main() {
	while (1) {
		Init();
		StartDraw();
		int menu_num = MenuDraw();
		if (menu_num == 0)  // 게임시작 버튼이 눌렸으면
			GameStart();
		if (menu_num == 2)
			break;
	}

	return 0;
}