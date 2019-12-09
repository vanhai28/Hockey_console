#pragma once
#include <string>
#include <Windows.h>

using namespace std;


int randomRange(int start, int end);


//Chuyen mot chuoi sang mot so
int tryParseInt(string line);


//dua con tro ghi toi vi tri (x,y)
void gotoXY(int x, int y, HANDLE& h);