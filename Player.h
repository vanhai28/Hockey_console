#pragma once
#include <Windows.h>
#include <iostream>
#include "Item.h"
#include "ConstVariable.h"

using namespace std;


class Player
{
private:
	int _x, _y; // Toa do (x, y) hien tai cua thanh choi
	int _size; // kich co 1/2 thanh choi
	int _ox, _oy; // Toa do (x, y) cu cua thanh choi
	int _vx; // Van toc di chuyen thanh choi
	int score;
	int level;
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

	int Score() { return score; }
	void setScore(int val) { score = val; }

	void setLevel(int val) { level = val; }
	int getLevel() { return level; }

	bool move();


public:
	Player();
	~Player();
	Player(int, int, int); // Khoi tao
	void Draw(HANDLE&); // Ve thanh choi

	void saveAchievement();

	void getItem(Item  item[], int numItem, HANDLE&h);

	//Hien thi bang thanh tich
	void showAchievemert(HANDLE h);
};

