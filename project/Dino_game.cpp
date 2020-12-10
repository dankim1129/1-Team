//[C/C++ game] very simple google dinosaur. (by. BlockDMask)

//2019.12.03 (v2.0)점수 추가, 충돌처리 추가.

#include<stdio.h>

#include<windows.h>

#include<conio.h>

#include<time.h>

 

 

#define DINO_BOTTOM_Y 12

#define TREE_BOTTOM_Y 20

#define TREE_BOTTOM_X 45

#define COIN_BOTTOM_Y 7

#define COIN_CNT 3

 

//콘솔 창의 크기와 제목을 지정하는 함수

void SetConsoleView()

{

	system("mode con:cols=100 lines=25");

	system("title Google Dinosaurs. By BlockDMask.");

}

 

//커서의 위치를 x, y로 이동하는 함수

void GotoXY(int x, int y)

{

	COORD Pos;

	Pos.X = 2 * x;

	Pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

 

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수

int GetKeyDown()

{

	if (_kbhit() != 0)

	{

		return _getch();

	}

	return 0;

}

 

//공룡을 그리는 함수

void DrawDino(int dinoY)

{

	GotoXY(0, dinoY);

	static bool legFlag = true;

	printf("        $$$$$$$ \n");

	printf("       $$ $$$$$$\n");

	printf("       $$$$$$$$$\n");

	printf("$      $$$      \n");

	printf("$$     $$$$$$$  \n");

	printf("$$$   $$$$$     \n");

	printf(" $$  $$$$$$$$$$ \n");

	printf(" $$$$$$$$$$$    \n");

	printf("  $$$$$$$$$$    \n");

	printf("    $$$$$$$$    \n");

	printf("     $$$$$$     \n");

	if (legFlag)

	{

		printf("     $    $$$    \n");

		printf("     $$          ");

		legFlag = false;

	}

	else

	{

		printf("     $$$  $     \n");

		printf("          $$    ");

		legFlag = true;

	}

}

 

//나무를 그리는 함수

void DrawTree(int treeX)

{

	GotoXY(treeX, TREE_BOTTOM_Y);

	printf("$$$$");

	GotoXY(treeX, TREE_BOTTOM_Y + 1);

	printf(" $$ ");

	GotoXY(treeX, TREE_BOTTOM_Y + 2);

	printf(" $$ ");

	GotoXY(treeX, TREE_BOTTOM_Y + 3);

	printf(" $$ ");

	GotoXY(treeX, TREE_BOTTOM_Y + 4);

	printf(" $$ ");

}

 

//점수 획득 코인을 그리는 함수

void DrawCoin(int coinX)

{

	GotoXY(coinX, COIN_BOTTOM_Y);

	printf("++");

	GotoXY(coinX, COIN_BOTTOM_Y + 1);

	printf("++");

}

 

//점수 감소 코인을 그리는 함수

void DrawCoin2(int coin2X)

{

	GotoXY(coin2X, COIN_BOTTOM_Y);

	printf("--");

	GotoXY(coin2X, COIN_BOTTOM_Y + 1);

	printf("--");

	

}

 

 

//(v2.0) 충돌 했을때 게임오버 그려줌

void DrawGameOver(const int score)

{

	system("cls");

	int x = 18;

	int y = 8;

	GotoXY(x, y);

	printf("===========================");

	GotoXY(x, y + 1);

	printf("======G A M E O V E R======");

	GotoXY(x, y + 2);

	printf("===========================");

	GotoXY(x, y + 5);

	printf("SCORE : %d", score);

 

	printf("\n\n\n\n\n\n\n\n\n");

	system("pause");

}

 

//(v2.0) 충돌했으면 true, 아니면 false

bool isCollision(const int treeX, const int dinoY)

{

	//트리의 X가 공룡의 몸체쪽에 있을때,

	//공룡의 높이가 충분하지 않다면 충돌로 처리

	GotoXY(0, 0);

	printf("treeX : %d, dinoY : %d", treeX, dinoY); //이런식으로 적절한 X, Y를 찾습니다.

	if (treeX <= 8 && treeX >= 4 &&

		dinoY > 8)

	{

		return true;

	}

	return false;

}

 

bool isCoin(const int coinX, const int dinoY)

{

	if (coinX == 6 && dinoY < 8)

		return true;

	return false;

}

 

bool isCoin2(const int coin2X, const int dinoY) 

{

	if(coin2X == 6 && dinoY < 8)

		return true;

	return false;

}

 

int main()

{

	SetConsoleView();

 

	while (true)		//(v2.0) 게임 루프

	{

		//게임 시작시 초기화

		bool isJumping = false;

		bool isBottom = true;

		const int gravity = 3;

 

		int dinoY = DINO_BOTTOM_Y;

		int treeX = TREE_BOTTOM_X;

		int coinX = TREE_BOTTOM_X + 1;

		int coin2X[COIN_CNT];

 

		int score = 0, score2 = 0;	//score : time, score2 : 코인으로 얻은 점수

		int life = 99999;		//시작 목숨 갯수 초기화

		clock_t start, curr;	//점수 변수 초기화

		start = clock();		//시작시간 초기화

		int tmp1 = 0;

		bool check2 = false;

 

 

 

 

 

 

		bool coinCheck[COIN_CNT];				//코인 등장 시간대 조절 

		for (int i = 0; i < COIN_CNT; i++)

			coinCheck[i] = false;

		for (int i = 0; i < COIN_CNT; i++)

			coin2X[i] = TREE_BOTTOM_X + 1;

		int cnt = 0;							//코인 등장 시간 측정용

 

		while (true)	//한 판에 대한 루프

		{

			//코인 등장 시간 지연 시킴

			cnt++;

			for (int i = 0; i < COIN_CNT; i++) 

				if (cnt == i * 6 + 6)

					coinCheck[i] = true;

			

 

			

			if (tmp1 < 5)

				tmp1++;

 

			//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단

			if (isCollision(treeX, dinoY)) {

				check2 = true;

				tmp1 = 0;

			}

 

			//

			if (tmp1 == 2 && check2) {

				life--;

				check2 = false;

			}

 

 

			//점수 획득 코인을 먹을 시

			if (isCoin(coinX, dinoY)) 

				score2++;

			

			//점수 감소 코인을 먹을 시

			for (int i = 0; i < COIN_CNT; i++) 

				if (coinCheck[i] && isCoin2(coin2X[i], dinoY))

					score2--;

 

			// 생명이 0이면 게임 종료

			if (life == 0)

				break;

			

			//z키가 눌렸고, 바닥이 아닐때 점프

			if (GetKeyDown() == 'z' && isBottom)

			{

				isJumping = true;

				isBottom = false;

			}

 

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.

			if (isJumping)

			{

				dinoY -= gravity;

			}

			else

			{

				dinoY += gravity;

			}

 

			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.

			if (dinoY >= DINO_BOTTOM_Y)

			{

				dinoY = DINO_BOTTOM_Y;

				isBottom = true;

			}

 

			//나무가 왼쪽으로 (x음수) 가도록하고

			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.

			treeX -= 2;

			if (treeX <= 0)

			{

				treeX = TREE_BOTTOM_X;

			}

 

			//동전이 왼쪽으로 (x음수) 가도록하고

			//동전의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.

			coinX -= 2;

			if (coinX <= 0)

				coinX = TREE_BOTTOM_X + 1;

 

			for (int i = 0; i < COIN_CNT; i++)

				if (coinCheck[i]) {

					coin2X[i] -= 2;

					if (coin2X[i] <= 0)

						coin2X[i] = TREE_BOTTOM_X + 1;

				}

 

 

			//점프의 맨위를 찍으면 점프가 끝난 상황.

			if (dinoY <= 3)

				{

					isJumping = false;

				}

			

 

			DrawDino(dinoY);		//draw dino

			DrawCoin(coinX);		//draw Coin

			for (int i = 0; i < COIN_CNT; i++)

				if (coinCheck[i])

					DrawCoin2(coin2X[i]);

			DrawTree(treeX);		//draw Tree

 

 

 

			

			//(v2.0)

			curr = clock();			//현재시간 받아오기

			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을떄

			{

				score++;	//스코어 UP

				start = clock();	//시작시간 초기화

			}

			Sleep(60);

			system("cls");	//clear

 

			//(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.

			GotoXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌

			printf("Score : %d\t", score);	//점수 출력해줌.

			printf("Life : %d\t", life);

			printf("Score2 : %d", score2);

			

		}

 

		//(v2.0) 게임 오버 메뉴

		DrawGameOver(score);

	}

	return 0;

}

 

//pull request tes
