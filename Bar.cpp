#include "Bar.h"
#include <cstdlib>
#include <ctime>

Bar::Bar()
{

}

Bar::~Bar()
{

}

Point2D Bar::Pos()
{
	return _pos;
}

void Bar::SetPos(Point2D newPos)
{
	_pos = newPos;
}

void Bar::DrawBar(char c)
{
	int x = _pos.X(), y = _pos.Y();
	Point2D temp(x - 4, y);
	temp.GoTo();
	printf("%c%c%c%c%c", c, c, c, c, c);
}

void Bar::MoveBarToLeft()
{
	DrawBar(' ');
	int x = _pos.X() - 1;
	_pos.SetX(x);
	DrawBar(char(219));
}

void Bar::MoveBarToRight()
{
	DrawBar(' ');
	int x = _pos.X() + 1;
	_pos.SetX(x);
	DrawBar(char(219));
}

//Bạn sẽ thua khi bar di chuyển sai 1 đơn vị hoành độ
void Bar::AutoMove(int x, int width)
{
	int a = rand() % 101 + 1;			//Tỷ lệ thắng của bạn xấp xỉ (100- (80 + 2 * _level))%
	if (a > 80 + 2 * _level)
	{
		if (5 < x && x < width)
		{
				DrawBar(' ');
				_pos.SetX(x - 1);		//Di chuyển sai
				DrawBar(char(219));
		}
	}
	//Di chuyển đúng
	else if (4 < x && x < width)
	{
		DrawBar(' ');
		_pos.SetX(x);
		DrawBar(char(219));
	}
}

