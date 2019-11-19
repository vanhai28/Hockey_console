#include "Ball.h"
#include "iostream"
using namespace std;

Ball::Ball()
{
	_height_state = 'D';	//Down
	_width_state = 'L';		//Left
	_state = 'T';			//True
}
Ball::~Ball()
{

}
char Ball::HeightState()
{
	return _height_state;
}
void Ball::SetHeightState(char newState)
{
	if (newState == 'U' || newState == 'D')	//Bóng chỉ có 2 trạng thái là đang đi lên hoặc đang đi xuống thôi
	{
		_height_state = newState;
	}
}
char Ball::WidthState()
{
	return _width_state;
}
void Ball::SetWidthState(char newState)
{
	if (newState == 'L' || newState == 'R')	//Bóng chỉ có 2 trạng thái là đang đi sang trái hoặc đang đi sang phải thôi
	{
		_width_state = newState;
	}
}
char Ball::State()
{
	return _state;
}
void Ball::SetState(char newState)
{
	_state = newState;
}
void Ball::DrawBall(char c)
{
	_pos.GoTo();
	cout << c;
}
Point2D Ball::Pos()
{
	return _pos;
}
void Ball::SetPos(Point2D newPos)
{
	_pos = newPos;
}
void Ball::MoveBall(int height, int width)
{

	int x = _pos.X(), y = _pos.Y();

	DrawBall(' ');

	//Thay đổi trạng thái khi va chạm
	if ('T' == _state)
	{
		if (x >= width - 1)
		{
			SetWidthState('L');
		}
		else if (x <= 1)
		{
			SetWidthState('R');
		}
		if (y >= height - 3)
		{
			SetHeightState('U');
		}
		else if (y <= 3)
		{
			SetHeightState('D');
		}
	}

	//Thay đổi vị trí khi di chuyển
	if ('D' == _height_state)
	{
		_pos.SetY(y + 1);
	}
	else
	{
		_pos.SetY(y - 1);
	}
	if ('L' == _width_state)
	{
		_pos.SetX(x - 1);
	}
	else
	{
		_pos.SetX(x + 1);
	}

	DrawBall('O');
}