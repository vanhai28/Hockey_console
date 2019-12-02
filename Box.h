#pragma once

/*
color:
	26 : xam - lam
	46 : vang - luc
	63 : trang lam nhat
	71 : trang - do

*/
static int ListColor[4] = { 26,46,63,71 };
class Box
{

private:
	int _x;//toa do x
	int _y;//toa do y
	int width;//be ngang cua box
	int height;//chieu cao box
	int score;//Diem co trong hop
	int color;
	bool isBreak;

public:

	void displayBox();
	void hideBox();
	int X(){return _x;}
	void setX( int val ) { _x = val; }

	int Y() { return _y; }
	void setY(int val )  {_y = val; }

	int Color() {return color;}
	void setColor(int val) { 
		if (val >= 0 && val < 4)
		{
			color = ListColor[val];
		}
		else
		{
			color = ListColor[0];
		}
		 }

	int Score() { return score; }
	void setScore(int val) { score = val; }

	int Width() { return width; }
	int setwidth(int val) { width = val; }

	int Height() { return height; }
	void setheight(int val) { height = val; }
	
	bool IsBreak() { return isBreak; }
	void setIsBreak(bool val) { isBreak = val; }

	Box();
	~Box();
};

