#include<iostream>
#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define UP 72
#define DOWN 80
#define ENTER 13
using namespace std;

int default_x = 22;
int default_y = 15;

class highscore {
	string name;
	int score;
};

void init();
void Start();
void Gotoxy(int x, int y);
int MenuDraw();

int main() {
	init();
	Start();
	int menu_num = MenuDraw();
}
void init() {
	system("mode con cols=100 lines=25 | title dino");
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console_cursor;
	console_cursor.bVisible = 0;
	console_cursor.dwSize = 1;
	SetConsoleCursorInfo(console_handle, &console_cursor);
}

void Start() {

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

void Gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 2*x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int MenuDraw() {
	int cursor_x = default_x, cursor_y = default_y;
	Gotoxy(cursor_x - 2, cursor_y);
	cout << ">   게 임 시 작";
	Gotoxy(cursor_x, cursor_y + 1);
	cout << "최 고 점 수";
	Gotoxy(cursor_x, cursor_y + 2);
	cout << "종  료";

	while (1) {
		if (_kbhit()) {
			char keyinput = _getch();
			if (keyinput == -32) {
				keyinput = _getch();
				switch (keyinput) {
				case UP: {
					if (cursor_y > default_y) {
						Gotoxy(cursor_x - 2, cursor_y);
						printf(" ");
						Gotoxy(cursor_x - 2, --cursor_y);
						printf(">");
					}
					break;
				}
				case DOWN: {
					if (cursor_y < default_y + 2) {
						Gotoxy(cursor_x - 2, cursor_y);
						printf(" ");
						Gotoxy(cursor_x - 2, ++cursor_y);
						printf(">");
					}
					break;
				}
				}
			} else if(keyinput == ENTER)
				return cursor_y - default_y;
		}
	}
}
