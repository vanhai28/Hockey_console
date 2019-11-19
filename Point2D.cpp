#include "Point2D.h"

Point2D::Point2D(int x, int y)
{
	_x = x;
	_y = y;
}
Point2D::~Point2D()
{

}
int Point2D::X()
{
	return _x;
}
void Point2D::SetX(int newX)
{
	_x = newX;
}
int Point2D::Y()
{
	return _y;
}
void Point2D::SetY(int newY)
{
	_y = newY;
}
void Point2D::GoTo()
{
	COORD coord;
	coord.X = _x;
	coord.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
