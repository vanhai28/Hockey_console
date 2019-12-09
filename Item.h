#pragma once
#include <Windows.h>
#include <iostream>
#include "CommonFunction.h"
using namespace std;
const int NUM_CATORY_ITEM = 4;
enum catoryItem
{
	x2 = 0,
	x0_5 = 1,
	add10 = 2,
	sub10 = 3
};
const static string catory[NUM_CATORY_ITEM] = { "x2", "x0.5","+10", "-10" };
class Item
{
private:
	int _x, _y; // Toa do (x, y) hien tai cua qua Item
	int _ox, _oy; // Toa do (x, y) cu cua qua Item
	int _vx, _vy; // Van toc cua qua Item
	int cat;
	bool is_move;
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

	bool getIsMove() { return is_move; }
	void setIsMove(bool val) { is_move = val; }

	int getCatory() { return cat; }
	void setCatory(int val) { cat = val; }

	void resetCatoryRandom();

public:
	Item();
	~Item();
	Item(int, int); // Khoi tao
	void Draw(HANDLE&); // Ve qua bong
	void move();

	void deleteItem(HANDLE& h);
};

