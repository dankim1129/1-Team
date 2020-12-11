#pragma once
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

void DrawDino(int dinoY);
void DrawTree(int treeX);
void DrawGameOver(const int score);
bool isCollision(const int treeX, const int dinoY);
void GameStart();