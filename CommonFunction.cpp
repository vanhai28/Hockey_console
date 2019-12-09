#include "CommonFunction.h"
#include <random>

int randomRange(int start, int end)
{
	if (start > end || start < 0) return 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(start, end);

	return dist(mt);

}


int tryParseInt(string line)
{
	int result;

	try
	{
		result = stoi(line);
	}
	catch (exception ex)
	{
		result = 0;
	}

	return result;
}

void gotoXY(int x, int y, HANDLE& h)
{
	COORD c;

	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(h, c);
}