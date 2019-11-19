#pragma once
#include "Point2D.h"

class Ball
{
private:
	Point2D _pos;
	char _height_state;	//Báo hiệu bóng đang đi lên hay đi xuống.
	char _width_state; //Báo hiệu bóng đang sang trái hay sang phải.
	char _state;	//Báo hiệu bóng có còn trong vùng bar hứng được hay không.
public:
	Ball();
	~Ball();
public:
	Point2D Pos();

	void SetPos(Point2D newPos);

	char HeightState();
	void SetHeightState(char newState);

	char WidthState();
	void SetWidthState(char newState);

	char State();
	void SetState(char newState);

	void DrawBall(char c);
	void MoveBall(int height, int width);
};

