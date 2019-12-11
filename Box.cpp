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
	std::cout << temp.substr(0, width);
}

void Box::hideBox()
{
	COORD pos;
	pos.X = _x;
	pos.Y = _y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, pos);
	SetConsoleTextAttribute(h, 15);
	std::string temp = "           ";
	std::cout << temp.substr(0, width);//xoa box tren man hinh
	isBreak = true;//danh dau box da bi vo
}

void Box::setColor(int val)
{
	if (val >= 0 && val < 4)
	{
		color = ListColor[val];
	}
	else
	{
		color = ListColor[0];
	}

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

<<<<<<< Updated upstream
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
=======
void Box::setListBox(vector<Box>& list, const int& level)
{
	int heightOfList = 6;//chieu cao cua day box
	int sizeList = list.size();
	Box temp;//bien tam de lay chieu cao va chieu rong cua box
	int widthBox = temp.Width();
	int heightBox = temp.Height();

	//Khoi tao list neu list chua co box
	if (sizeList == 0)
	{
		int numBox = 0;

		for (int i = 0; i < heightOfList; i++)
		{
			//dem so luong box can khoi tao
>>>>>>> Stashed changes
			numBox += (WIDTH_BODER - 2 * (i + 2)) / widthBox;
		}

		for (int i = 0; i < numBox + heightBox; i++)
		{
<<<<<<< Updated upstream
=======
			//khoi tao box va them vao list
>>>>>>> Stashed changes
			list.push_back(Box());
		}
	}

	int index = 0;
<<<<<<< Updated upstream
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
=======
	int dum = 0;//tao khoang cach thut vao le o moi day box
	//khoi tao vi tri cho box
	for (int i = TOP_BODER; i < TOP_BODER + heightOfList; i += heightBox)
	{
		for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
		{
			list[index].setScore(rand() % 10 + level * 5);//khoi tao diem
			list[index].setColor(rand() % 4);//khoi tao mau sac
			list[index].setX(j);//khoi tao vi tri x
			list[index].setY(i);//khoi tao vi tri y
			list[index].setIsBreak(false);//khoi tao trang thai
>>>>>>> Stashed changes
			index++;
		}
		dum += 2;
	}
<<<<<<< Updated upstream

=======
	//Neu qua trinh khoi tao du bõ thi loai bo bot
>>>>>>> Stashed changes
	while ((int)list.size() > index)
	{
		list.pop_back();
	}
}

<<<<<<< Updated upstream
void Box:: displayListBox(vector<Box>& list)
=======
void Box::displayListBox(vector<Box>& list)
>>>>>>> Stashed changes
{
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		list[i].displayBox();
	}
}
