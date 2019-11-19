#pragma once
#include "Point2D.h"
class Bar
{
private:
	Point2D _pos;
	int _level = 8;			//Độ thông minh của bot, tăng dần từ 1 đến 10
public:
	Bar();
	~Bar();
public:
	Point2D Pos();
	void SetLevel(int lv) { _level = lv; }
	void SetPos(Point2D newPos);
	void DrawBar(char c);
	void MoveBarToLeft();
	void MoveBarToRight();
	void AutoMove(int x, int width);
};

