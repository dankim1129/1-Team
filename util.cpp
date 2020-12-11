#include "util.h"


void Init() {
	system("mode con cols=100 lines=25 | title dino");
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console_cursor;
	console_cursor.bVisible = 0;
	console_cursor.dwSize = 1;
	SetConsoleCursorInfo(console_handle, &console_cursor);
}

void GotoXY(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}