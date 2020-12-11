//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)���� �߰�, �浹ó�� �߰�.

#include <time.h>
#include "util.h"
#include "game.h"


//������ �׸��� �Լ�
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

void DrawCoin(int coinX)
{
	GotoXY(coinX, COIN_BOTTOM_Y);
	printf("++");
	GotoXY(coinX, COIN_BOTTOM_Y + 1);
	printf("++");
}

//���� ���� ������ �׸��� �Լ�

void DrawCoin2(int coin2X)
{
	GotoXY(coin2X, COIN_BOTTOM_Y);
	printf("--");
	GotoXY(coin2X, COIN_BOTTOM_Y + 1);
	printf("--");
}

//������ �׸��� �Լ�
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

//(v2.0) �浹 ������ ���ӿ��� �׷���
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

//(v2.0) �浹������ true, �ƴϸ� false
bool isCollision(const int treeX, const int dinoY)
{
	//Ʈ���� X�� ������ ��ü�ʿ� ������,
	//������ ���̰� ������� �ʴٸ� �浹�� ó��
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d", treeX, dinoY); //�̷������� ������ X, Y�� ã���ϴ�.
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
	if (coin2X == 6 && dinoY < 8)
		return true;
	return false;
}


void GameStart()
{
	//���� ���۽� �ʱ�ȭ
	bool isJumping = false;
	bool goingup = false;
	bool goingdown = false;
	bool isdoubleJumping = false;
	bool isBottom = true;
	const int gravity = 3;

	int dinoY = DINO_BOTTOM_Y;
	int treeX = TREE_BOTTOM_X;
	int coinX = TREE_BOTTOM_X + 1;
	int coin2X[COIN_CNT];

	int score = 0, score2 = 0;	//score : time, score2 : �������� ���� ����
	int life = 10;		//���� ��� ���� �ʱ�ȭ
	clock_t start, curr;	//���� ���� �ʱ�ȭ
	start = clock();		//���۽ð� �ʱ�ȭ
	int tmp1 = 0;
	bool check2 = false;
	bool coinCheck[COIN_CNT];				//���� ���� �ð��� ���� 
	for (int i = 0; i < COIN_CNT; i++)
		coinCheck[i] = false;

	for (int i = 0; i < COIN_CNT; i++)
		coin2X[i] = TREE_BOTTOM_X + 1;

	int cnt = 0;							//���� ���� �ð� ������

	while (true)	//�� �ǿ� ���� ����
	{
		//���� ���� �ð� ���� ��Ŵ

		cnt++;
		for (int i = 0; i < COIN_CNT; i++)
			if (cnt == i * 6 + 6)
				coinCheck[i] = true;

		if (tmp1 < 5)
			tmp1++;

		//(v2.0) �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
		if (isCollision(treeX, dinoY)) {
			check2 = true;
			tmp1 = 0;
		}

		if (tmp1 == 2 && check2) {
			life--;
			check2 = false;
		}

		//���� ȹ�� ������ ���� ��
		if (isCoin(coinX, dinoY))
			score2++;

		//���� ���� ������ ���� ��
		for (int i = 0; i < COIN_CNT; i++)
			if (coinCheck[i] && isCoin2(coin2X[i], dinoY))
				score2--;

		// ������ 0�̸� ���� ����

		if (life == 0)
			break;



		//zŰ�� ���Ȱ�, �ٴ��� �� ����
		if (GetKeyDown() == 'z' && isBottom)
		{
			isJumping = true;
			goingup = true;
			goingdown = false;
			isBottom = false;
		}

		//zŰ�� ���Ȱ�, ���� ���� �� ����
		if (GetKeyDown() == 'z' && isJumping == true)
		{
			goingup = true;
			goingdown = false;
			isdoubleJumping = true;
			isJumping = false;
		}


		//�������̶�� Y�� ����, ������ �������� Y�� ����.

		if (goingup)
		{
			dinoY -= gravity;
		}
		else if (goingdown)
		{
			dinoY += gravity;
		}

		//Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
		if (dinoY >= DINO_BOTTOM_Y)
		{
			dinoY = DINO_BOTTOM_Y;
			goingdown = false;
			isBottom = true;
		}

		//������ �������� (x����) �������ϰ�
		//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
		treeX -= 2;
		if (treeX <= 0)
		{
			treeX = TREE_BOTTOM_X;
		}
		//������ �������� (x����) �������ϰ�

		//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
		coinX -= 2;
		if (coinX <= 0)
			coinX = TREE_BOTTOM_X + 1;

		for (int i = 0; i < COIN_CNT; i++)
			if (coinCheck[i]) {
				coin2X[i] -= 2;
				if (coin2X[i] <= 0)
					coin2X[i] = TREE_BOTTOM_X + 1;
			}

		//������ �ѹ����� ������ ���� ��Ȳ.
		if (dinoY <= 3 && isdoubleJumping == true)
		{
			goingup = false;
			goingdown = true;
		}

		//������ �ι����� ������ ���� ��Ȳ.
		if (dinoY <= 8 && isJumping == true)
		{
			goingup = false;
			goingdown = true;
		}

		DrawDino(dinoY);		//draw dino
		DrawCoin(coinX);		//draw Coin
		for (int i = 0; i < COIN_CNT; i++)
			if (coinCheck[i])
				DrawCoin2(coin2X[i]);
		DrawTree(treeX);		//draw Tree

		//(v2.0)
		curr = clock();			//����ð� �޾ƿ���
		if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1�ʰ� �Ѿ�����
		{
			score++;	//���ھ� UP
			start = clock();	//���۽ð� �ʱ�ȭ
		}
		Sleep(60);
		system("cls");	//clear

		//(v2.0) ��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ���ݴϴ�.
		GotoXY(22, 0);	//Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
		printf("Score : %d\t", score + score2);	//���� �������.
		printf("Life : %d\t", life);

	}

	//(v2.0) ���� ���� �޴�
	DrawGameOver(score);

}

//pull request test
