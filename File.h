#pragma once
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
//luu vao diem cua nguoi choi va may vao file
void SaveToFile(int scoreplayer, int scorecomputer);

//tai cac diem da duoc luu len
void LoadFile(char mode, int &scoreplayer, int &scorecomputer);

//luu cac ddiem khian item
void savebest(int score);

//tai diem cao nhat
int Maxscore();