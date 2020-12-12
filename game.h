#pragma once

//게임 시작을 위한 헤더

#define DINO_BOTTOM_Y 12
#define BOX_BOTTOM_Y 23
#define BOX_BOTTOM_X 15
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define COIN_BOTTOM_Y 7
#define COIN_CNT 3

void DrawDino(int);
void DrawTree(int);
void DrawGameOver(const int);
bool isCollision(const int, const int);
bool isCoin(const int, const int);
bool isCoin2(const int, const int);
void GameStart();