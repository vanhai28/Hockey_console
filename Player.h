#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;
const int WIDTH_BODER = 55; // Chieu ngang san dau
const int HEIGHT_BODER = 35;
class Player
{
private:
	int _x, _y; // Toa do (x, y) hien tai cua thanh choi
	int _size; // kich co 1/2 thanh choi
	int _ox, _oy; // Toa do (x, y) cu cua thanh choi
	int _vx; // Van toc di chuyen thanh choi
public:
	//getter & setter
	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }

	void SetSize(int size) { _size = size; }
	int Size() { return _size; }

	void SetOX(int  ox) { _ox = ox; }
	void SetOY(int oy) { _oy = oy; }

	int VX() { return _vx; }
	void SetVX(int vx) { _vx = vx; }

	int X() { return _x; }
	int Y() { return _y; }

	int OX() { return _ox; }
	int OY() { return _oy; }

	bool move();
public:
	Player();
	~Player();
	Player(int, int, int); // Khoi tao
	void Draw(HANDLE&); // Ve thanh choi
};

