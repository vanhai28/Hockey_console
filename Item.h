#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
class Item
{
private:
	int _x, _y; // Toa do (x, y) hien tai cua qua Item
	int _ox, _oy; // Toa do (x, y) cu cua qua Item
	int _vx, _vy; // Van toc cua qua Item
public:
	//getter & setter
	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }

	void SetOX(int ox) { _ox = ox; }
	void SetOY(int oy) { _oy = oy; }

	void SetVX(int vx) { _vx = vx; }
	void SetVY(int vy) { _vy = vy; }

	int X() { return _x; }
	int Y() { return _y; }

	int OX() { return _ox; }
	int OY() { return _oy; }

	int VX() { return _vx; }
	int VY() { return _vy; }
public:
	Item();
	~Item();
	Item(int, int); // Khoi tao
	void Draw(HANDLE&); // Ve qua bong

};

