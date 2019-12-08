#pragma once
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
void SaveToFile(int scoreplayer, int scorecomputer);
void LoadFile(char mode, int &scoreplayer, int &scorecomputer);