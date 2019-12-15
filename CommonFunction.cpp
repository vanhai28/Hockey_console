#include "CommonFunction.h"
#include <random>

int randomRange(int start, int end)
{
	if (start > end || start < 0) return 0;
	//tao gia tri ngau nhien
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

void sortScore(vector<playerInfor>& list)
{

	for (int i = 0; i < list.size() - 1; i++)
	{
		for (int j = list.size()-1; j>i; j--)
		{
			if (list[j-1].score < list[j].score)
			{
				playerInfor temp = list[j];
				list[j] = list[j-1];
				list[j-1] = temp;
			}
		}
	}
}
