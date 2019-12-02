#pragma once
#include "Box.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Ball.h"
#include "Player.h"
#include <vector>
const int TOP_BODER = 6;
const int LEFT_BODER = 1;
//An con tro chuot tren man hinh

void Nocursortype();

// Input: you(thanh choi cua ban), com(thanh choi cua may), b(bong), started(co kiem tra ket thuc tran), 
// yourScore(diem cua ban), computerScore(diem cua may), h(con tro su dung voi man hinh console)
// Output: Man hinh choi ban dau
// Chuc nang: Reset lai san dau khi ban thang hoac may thang
void ResetResult(Player& you, Player& com, Ball& b, bool& started, int& yourScore, int& computerScore, HANDLE& h);
void DrawBorder(HANDLE &h);
void gotoXY(int x,int y, HANDLE& h);

void setListBox(vector<Box>& list, const int & level);

void displayListBox(vector<Box>& list);

bool checkBallCollideBox(Ball& ball, vector<Box>& list,int &score );

void saveAchievement(int level, int score);


void showAchievemert(HANDLE h);

void loadGame(int &level);

int tryParseInt(string line);
