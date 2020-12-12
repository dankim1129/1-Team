#pragma once
#define DINO_BOTTOM_Y 12
#define BOX_BOTTOM_Y 23
#define BOX_BOTTOM_X 15
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define COIN_BOTTOM_Y 7
#define COIN_CNT 3

void DrawDino(int dinoY);
void DrawTree(int treeX);
void DrawBox(int boxX);
void DrawGameOver(const int score);
bool isCollision(const int treeX, const int boxX, const int dinoY);
void GameStart();
void ShowScore();
bool isCoin(const int coinX, const int dinoY);
bool isCoin2(const int coin2X, const int dinoY);