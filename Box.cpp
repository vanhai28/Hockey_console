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
	PlaySound(L"disappear.wav", NULL, SND_FILENAME || SND_ASYNC);//phat am thanh bien mat
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

void Box::setListBox(vector<Box>& list, const int& level)
{
	int heightOfList = 9;//chieu cao cua day box
	int sizeList = (int)list.size();
	Box temp;//bien tam de lay chieu cao va chieu rong cua box
	int widthBox = temp.Width();
	int heightBox = temp.Height();
	list.clear();

	int index = 0;
	int dum = 0;//tao khoang cach thut vao le o moi day box
	//khoi tao vi tri cho box
	//level 1
	int temp_1 = 4;
	switch (level)
	{
	case 1:
		for (int i = TOP_BODER; i < TOP_BODER + heightOfList; i += heightBox)
		{
			for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
			{
				if (j >= LEFT_BODER + widthBox * temp_1 + dum && j < WIDTH_BODER - widthBox * temp_1 - dum - 2)
				{
					continue;
				}

				temp.setScore(rand() % 10 + level * 5);//khoi tao diem
				temp.setColor(rand() % 4);//khoi tao mau sac
				temp.setX(j);//khoi tao vi tri x
				temp.setY(i);//khoi tao vi tri y
				temp.setIsBreak(false);//khoi tao trang thai
				list.push_back(temp);
			}
			dum += 2;
		}
		break;
	case 2:
		//tao map cho level 2
		temp_1 = 4;
		heightOfList = 9;
		dum = 8;
		for (int i = TOP_BODER; i < TOP_BODER + heightOfList; i += heightBox)
		{
			for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
			{
				if (j >= LEFT_BODER + widthBox * temp_1 + dum && j < WIDTH_BODER - widthBox * temp_1 - dum - 2)
				{
					continue;
				}

				temp.setScore(rand() % 10 + level * 5);//khoi tao diem
				temp.setColor(rand() % 4);//khoi tao mau sac
				temp.setX(j);//khoi tao vi tri x
				temp.setY(i);//khoi tao vi tri y
				temp.setIsBreak(false);//khoi tao trang thai
				list.push_back(temp);
			}

			if (i < TOP_BODER + 4)
			{
				dum -= 2;
			}
			else
			{
				dum += 2;
			}

		}
		break;
	case 3:
		temp_1 = 4;
		heightOfList = 9;
		for (int i = TOP_BODER; i < TOP_BODER + heightOfList; i += heightBox)
		{
			for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
			{
				if (j >= LEFT_BODER + widthBox * temp_1 + dum && j < WIDTH_BODER - widthBox * temp_1 - dum - 2)
				{
					continue;
				}

				temp.setScore(rand() % 10 + level * 5);//khoi tao diem
				temp.setColor(rand() % 4);//khoi tao mau sac
				temp.setX(j);//khoi tao vi tri x
				temp.setY(i);//khoi tao vi tri y
				temp.setIsBreak(false);//khoi tao trang thai
				list.push_back(temp);
			}

			if (i < TOP_BODER + 4)
			{
				dum += 2;
			}
			else
			{
				dum -= 2;
			}

		}
		break;
	case 4:
		
		//Man chu A
		temp_1 = 3;
		heightOfList = 8;
		for (int i = TOP_BODER + heightOfList - 1; i > TOP_BODER; i -= heightBox)
		{
			for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
			{
				if (i != TOP_BODER + heightOfList - 1 - 2 * heightBox &&
					i != TOP_BODER + heightOfList - 1 - 3 * heightBox &&
					j >= LEFT_BODER + widthBox * temp_1 + dum && j < WIDTH_BODER - widthBox * temp_1 - dum - 2)
				{
					continue;
				}

				temp.setScore(rand() % 10 + level * 5);//khoi tao diem
				temp.setColor(rand() % 4);//khoi tao mau sac
				temp.setX(j);//khoi tao vi tri x
				temp.setY(i);//khoi tao vi tri y
				temp.setIsBreak(false);//khoi tao trang thai
				list.push_back(temp);
			}

			dum += 2;


		}
		break;
	case 5:
		//tao man choi cho level 5
		temp_1 = 6;

		for (int i = TOP_BODER + 1 + 6; i > TOP_BODER; i -= heightBox)
		{
			for (int j = LEFT_BODER + dum; j < WIDTH_BODER - dum - widthBox; j += widthBox)
			{
				if (j >= LEFT_BODER + widthBox * temp_1 + dum && j < WIDTH_BODER - widthBox * temp_1 - dum - 2)
				{
					continue;
				}

				if (i == TOP_BODER + 1 + 6 && (j < 2 * widthBox || j > 4 * widthBox) && (j < 9 * widthBox || j > 11 * widthBox)) continue;
				temp.setScore(rand() % 10 + level * 5);//khoi tao diem
				temp.setColor(rand() % 4);//khoi tao mau sac
				temp.setX(j);//khoi tao vi tri x
				temp.setY(i);//khoi tao vi tri y
				temp.setIsBreak(false);//khoi tao trang thailist[index].setIsBreak(false);//khoi tao trang thai
				list.push_back(temp);
			}

			if (i != TOP_BODER + 1 + 6)
			{
				temp_1--;
				dum += 2;
			}

		}
		break;
	default://case >= 6
		//Man chu H
		temp_1 = 5;
		heightOfList = 8;
		for (int i = TOP_BODER + heightOfList - 1; i > TOP_BODER; i -= heightBox)
		{
			for (int j = LEFT_BODER + widthBox; j < WIDTH_BODER - dum - 2 * widthBox; j += widthBox)
			{
				if (i != TOP_BODER + heightOfList - 1 - 2 * heightBox &&
					i != TOP_BODER + heightOfList - 1 - 3 * heightBox &&
					i != TOP_BODER + heightOfList - 1 - 4 * heightBox &&
					j >= LEFT_BODER + widthBox * temp_1 + dum && j < WIDTH_BODER - widthBox * temp_1 - dum - 2)
				{
					continue;
				}

				temp.setScore(rand() % 10 + level * 5);//khoi tao diem
				temp.setColor(rand() % 4);//khoi tao mau sac
				temp.setX(j);//khoi tao vi tri x
				temp.setY(i);//khoi tao vi tri y
				temp.setIsBreak(false);//khoi tao trang thai
				list.push_back(temp);
			}
		}
		break;

	}

}

void Box::displayListBox(vector<Box>& list)
{
	int size = (int)list.size();

	for (int i = 0; i < size; i++)
	{
		list[i].displayBox();
	}
}
