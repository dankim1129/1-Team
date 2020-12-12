#pragma once


// 처음 초기화를 하거나 커서위치를 바꾸거나 키보드 입력이 들어왔는지 확인하는 헤더

#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <conio.h>

using namespace std;

void Init();
void GotoXY(int, int);
int GetKeyDown();