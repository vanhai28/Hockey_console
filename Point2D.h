#pragma once
#include <thread>
#include "Windows.h"
#include "conio.h"

class Point2D
{
private:
	int _x;
	int _y;
public:
	Point2D(int x = 0, int y = 0);
	~Point2D();
public:
	int X();
	void SetX(int newX);
	int Y();
	void SetY(int newY);
	void GoTo();
};

