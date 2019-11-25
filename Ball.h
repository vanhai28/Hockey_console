#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class Ball
{
private:
	int _x, _y; // Toa do (x, y) hien tai cua qua bong
	int _ox, _oy; // Toa do (x, y) cu cua qua bong
	float _vx, _vy; // Van toc cua qua bong
public:
	//getter & setter
	void SetX(float x) { _x = (int)x; }
	void SetY(float y) { _y = (int)y; }

	void SetOX(float ox) { _ox = (int)ox; }
	void SetOY(float oy) { _oy = (int)oy; }

	void SetVX(float vx) { _vx = vx; }
	void SetVY(float vy) { _vy = vy; }

	int X() { return _x; }
	int Y() { return _y; }

	int OX() { return _ox; }
	int OY() { return _oy; }

	float VX() { return _vx; }
	float VY() { return _vy; }
public:
	Ball();
	~Ball();
	Ball(int, int); // Khoi tao
	void Draw(HANDLE&); // Ve qua bong
};

