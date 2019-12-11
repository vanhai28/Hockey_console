
#pragma once
#include "Box.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Ball.h"
#include "Player.h"
#include <vector>
#include <iomanip>
#include <conio.h>
const int TOP_BODER = 6;
const int LEFT_BODER = 1;


//An con tro chuot tren man hinh
//Khoa kich thuoc man hinh
void Nocursortype();

// Input: you(thanh choi cua ban), com(thanh choi cua may), b(bong), started(co kiem tra ket thuc tran), 
// yourScore(diem cua ban), computerScore(diem cua may), h(con tro su dung voi man hinh console)
// Output: Man hinh choi ban dau
// Chuc nang: Reset lai san dau khi ban thang hoac may thang
void ResetResult(Player& you, Player& com, Ball& b, bool& started, int& yourScore, int& computerScore, HANDLE& h);

//Reset toa do bong, thanh truot , diem
void ResetGame(Player& you, Ball& b, bool& started, int& yourScore, HANDLE& h);

// Ve khung man hinh
void DrawBorder(HANDLE& h);

//dua con tro ghi toi vi tri (x,y)
void gotoXY(int x, int y, HANDLE& h);

//Khoi tao cac thong so cho danh sach cac hop
void setListBox(vector<Box>& list, const int& level);

//Hien thi cac hop ra man hinh
void displayListBox(vector<Box>& list);

//Kiem tra su va cham cua bong va cac hop
bool checkBallCollideBox(Ball& ball, vector<Box>& list, int& score);

//Luu thanh tich vao file
void saveAchievement(int level, int score);

//Hien thi bang thanh tich
void showAchievemert(HANDLE h);

//Tai du lieu game tu file
void loadGame(char mode, int& level);

//Chuyen mot chuoi sang mot so
int tryParseInt(string line);


//Man choi bong va hop
void stagePingpongBox(Player you, Ball ball, HANDLE h);

//màn chơi hockey
void playPingpong(Player you, Player computer);

// cac chuc nang cua menu
void Choosemenu(char& key, HANDLE h);

//vẽ menu cho game
void DrawMenu(char& key, HANDLE &h);

//menu
void menu(char& key, HANDLE &h);

//đọc fle hướng dẫn
void ReadGuide(char& key, HANDLE& h);