#include "Box.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
using namespace std;

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

void Box:: setListBox(vector<Box>& list, const int& level)
{
	int heightOfList = 6;
	int sizeList = list.size();
	Box temp;
	int widthBox = temp.Width();
	int heightBox = temp.Height();

	if (sizeList == 0)
	{

		int numBox = 0;
		for (int i = 0; i < heightOfList; i++)
		{
			numBox += (WIDTH_BODER - 2 * (i + 2)) / widthBox;
		}

		for (int i = 0; i < numBox + heightBox; i++)
		{
			list.push_back(Box());
		}
	}

	int index = 0;
	int dum = 0;

	for (int i = TOP_BODER + 1; i < TOP_BODER + heightOfList; i += heightBox)
	{
		for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
		{
			list[index].setScore(rand() % 10 + level * 5);
			list[index].setColor(rand() % 4);
			list[index].setX(j);
			list[index].setY(i);
			list[index].setIsBreak(false);
			index++;
		}
		dum += 2;
	}

	while ((int)list.size() > index)
	{
		list.pop_back();
	}
}

void Box:: displayListBox(vector<Box>& list)
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		list[i].displayBox();
	}
}
