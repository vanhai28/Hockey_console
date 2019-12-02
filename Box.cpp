#include "Box.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>


void Box::displayBox()
{
	COORD pos;
	pos.X = _x;
	pos.Y = _y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, pos);
	SetConsoleTextAttribute(h, color);
	std::string temp = std::to_string(score).append("   ");
	std::cout << temp.substr(0,width);
}

void Box::hideBox()
{
	COORD pos;
	pos.X = _x;
	pos.Y = _y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, pos);
	SetConsoleTextAttribute(h, 15);
	std::string temp = "       ";
	std::cout << temp.substr(0, width);
	isBreak = true;
}

Box::Box()
{
	color = ListColor[rand() % 4];
	score = rand() % 10 + 6;
	width = 4;
	height = 1;
	_x = 0;
	_y = 0;
	isBreak = false;

}


Box::~Box()
{
}
