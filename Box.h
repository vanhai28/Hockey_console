#pragma once
#include <vector>
#include "ConstVariable.h"
//Danh sach mau sac cua box
static int ListColor[4] = { 26,46,63,71 };
class Box
{
private:
	int _x;//toa do x
	int _y;//toa do y
	int width;//be ngang cua box
	int height;//chieu cao box
	int score;//Diem co trong hop
	int color;//Mau sac cua box
	bool isBreak;//Kiem tra trang thai box da vo hoac khong

public:

	//Hien thi box len man hinh
	void displayBox();

	//xoa box tren man hinh
	void hideBox();

	//---------- GETTER - SETTER------------
	int X() { return _x; }
	void setX(int val) { _x = val; }

	int Y() { return _y; }
	void setY(int val) { _y = val; }

	int Color() { return color; }
	void setColor(int val);

	int Score() { return score; }
	void setScore(int val) { score = val; }

	int Width() { return width; }
	void setWidth(int val) { width = val; }

	int Height() { return height; }
	void setheight(int val) { height = val; }

	bool IsBreak() { return isBreak; }
	void setIsBreak(bool val) { isBreak = val; }
	//---------------------------------------
	Box();
	~Box();

public:
	//Khoi tao cac thong so cho danh sach cac hop
	// Tham so list : danh sach box can khoi tao gia tri
	// Tham so level : level cua nguoi choi de khoi tao diem cua box
	static void setListBox(std::vector<Box>& list, const int & level);

	//Hien thi cac hop ra man hinh
	// Tham so list : danh sach box can hien thi
	static void displayListBox(std::vector<Box>& list);
};

