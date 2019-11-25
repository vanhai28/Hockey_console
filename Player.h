#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class Player
{
private:
	float _x, _y; // Toa do (x, y) hien tai cua thanh choi
	int _size; // kich co 1/2 thanh choi
	float _ox, _oy; // Toa do (x, y) cu cua thanh choi
	float _vx; // Van toc di chuyen thanh choi
public:
	//getter & setter
	void SetX(float x) { _x = x; }
	void SetY(float y) { _y = y; }

	void SetSize(int size) { _size = size; }
	int Size() { return _size; }

	void SetOX(float ox) { _ox = ox; }
	void SetOY(float oy) { _oy = oy; }

	float VX() { return _vx; }
	void SetVX(float vx) { _vx = vx; }

	float X() { return _x; }
	float Y() { return _y; }

	float OX() { return _ox; }
	float OY() { return _oy; }

public:
	Player();
	~Player();
	Player(int, int, int); // Khoi tao
	void Draw(HANDLE&); // Ve thanh choi
};

