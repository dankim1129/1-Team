#pragma once
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define COIN_BOTTOM_Y 7
#define COIN_CNT 3

void DrawDino(int dinoY);
void DrawTree(int treeX);
void DrawGameOver(const int score);
bool isCollision(const int treeX, const int dinoY);
void GameStart();
bool isCoin(const int coinX, const int dinoY);
bool isCoin2(const int coin2X, const int dinoY);