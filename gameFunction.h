#pragma once
#include "Box.h"
#include <iostream>
#include <ctime>
#include "Ball.h"
#include "Player.h"
#include <vector>
#include <iomanip>
#include <conio.h>

//An con tro chuot tren man hinh
//Khoa kich thuoc man hinh
void Nocursortype();

// Input: you(thanh choi cua ban), com(thanh choi cua may), b(bong), started(co kiem tra ket thuc tran), 
// yourScore(diem cua ban), computerScore(diem cua may), h(con tro su dung voi man hinh console)
// Output: Man hinh choi ban dau
// Chuc nang: Reset lai san dau khi ban thang hoac may thang
void ResetResult(Player& you, Player& com, Ball& b, int& yourScore, int& computerScore, HANDLE& h);

//Reset toa do bong, thanh truot , diem
//su dung trong man choi 2
void ResetGame(Player& you, Ball& b, bool& started, HANDLE& h);

// Ve khung man hinh
void DrawBorder(HANDLE &h);

//Tai du lieu game tu file
void loadGame(char mode, int &level);

//Man choi bong va hop
void stagePingpongBox(Player you, Ball ball, HANDLE h);


//Man choi voi may
void playPingpong(Player you, Player computer);

//Ve man hinh menu
void DrawMenu(char& key, HANDLE& h);

//Hien thi menu de lua chon chuc nang
void showMenu(char& key, HANDLE h);

//Hien thi chuc nang huong dan trong game
void ReadGuide(char& key, HANDLE& h);

//Ve dong chu PingPong
void drawTextPingpong(HANDLE &h, int x, int y);

//Hien thi top diem cao nhat va ten nguoi choi len man hinh
void showTopBestScore(vector<playerInfor> list, HANDLE &h);

//Xoa map sau khi choi xong
void deleteMap(vector<Box>& list);
