#include "interface.h"
#include "util.h"

using namespace std;

static int default_x = 22;
static int default_y = 15;

void StartDraw() {

	cout << endl << endl << endl << endl;
	printf("                        ########      ########   ######      ####      #####                        ");
	printf("                        #########       ####     #######     ####    #########                      ");
	printf("                        ###    ###      ####     #### ###    ####   ###     ###                     ");
	printf("                        ###     ###     ####     ####  ###   ####   ###     ###                     ");
	printf("                        ###     ###     ####     ####   ###  ####   ###     ###                     ");
	printf("                        ###    ###      ####     ####    ### ####   ###     ###                     ");
	printf("                        ###   ###       ####     ####     #######    #########                      ");
	printf("                        ########      ########   ####      ######      #####                        ");

}

int MenuDraw() {
	int cursor_x = default_x, cursor_y = default_y;
	GotoXY(cursor_x - 2, cursor_y);
	cout << ">   게 임 시 작";
	GotoXY(cursor_x, cursor_y + 1);
	cout << "현 재 순 위";
	GotoXY(cursor_x, cursor_y + 2);
	cout << "종  료";

	while (1) {
		char keyinput = GetKeyDown();
		if (keyinput == -32) {
			keyinput = _getch();
			switch (keyinput) {
			case UP:
				if (cursor_y > default_y) {
					GotoXY(cursor_x - 2, cursor_y);
					printf(" ");
					GotoXY(cursor_x - 2, --cursor_y);
					printf(">");
				}
				break;
			case DOWN:
				if (cursor_y < default_y + 2) {
					GotoXY(cursor_x - 2, cursor_y);
					printf(" ");
					GotoXY(cursor_x - 2, ++cursor_y);
					printf(">");
				}
				break;
			default:
				continue;
			}
		} else if(keyinput == ENTER)
			return cursor_y - default_y;
	}
}
