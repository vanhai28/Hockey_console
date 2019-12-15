#pragma once
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
#include <vector>
#include "CommonFunction.h"
using namespace std;
<<<<<<< Updated upstream
void SaveToFile(int scoreplayer, int scorecomputer);
void LoadFile(char mode, int &scoreplayer, int &scorecomputer);
=======

//luu vao diem cua nguoi choi va may vao file
void SaveToFile(int scoreplayer, int scorecomputer, vector<playerInfor> listPlayer);

//tai cac diem da duoc luu len
void LoadFile(char mode, int &scoreplayer, int &scorecomputer, vector<playerInfor> &list);



////tai diem cao nhat
//int Maxscore();
>>>>>>> Stashed changes
