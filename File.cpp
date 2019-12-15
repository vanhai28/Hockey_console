#include "File.h"


void SaveToFile(int scoreplayer, int scorecomputer)
{
<<<<<<< Updated upstream
	
=======

>>>>>>> Stashed changes
	fstream savefile;
	savefile.open("Save.txt", ios::out);

	savefile << scoreplayer << endl;
	savefile << scorecomputer << endl;

	savefile.close();
}

void LoadFile(char mode, int &scoreplayer, int & scorecomputer)
{
	fstream loadfile;

<<<<<<< Updated upstream
=======
	if (loadfile.fail())
	{
		cout << "ban chua luu game" << endl;
	}
	list.clear();
>>>>>>> Stashed changes
	if (mode == '2')
	{
		scoreplayer = 0;
		scorecomputer = 0;
	}
	else
	{
		loadfile.open("Save.txt", ios::in);

		if (loadfile.fail())
		{
			cout << "ban chua luu game" << endl;
		}
		loadfile >> scoreplayer;
		loadfile >> scorecomputer;

		loadfile.close();
	}

<<<<<<< Updated upstream
}
=======
	while (!loadfile.eof())
	{
		do
		{
			getline(loadfile, line);
		} while (line.empty() && !loadfile.eof());
>>>>>>> Stashed changes

void savebest(int score)
{
	fstream outfile;
	outfile.open("Savebest.txt", ios::out | ios::app);

	outfile << score << endl;
	outfile.close();
}

int Maxscore()
{
	fstream scorefile;
	scorefile.open("Savebest.txt", ios::in);

	if (scorefile.fail())
	{
		cout << "khong mo duoc fine" << endl;
		return 0;
	}
	int max = 0;
	string data;
	while (scorefile.good())
	{
		getline(scorefile, data);
		if ((int)atoi(data.c_str()) > max)
		{
			max = (int)atoi(data.c_str());
		}
	}
	scorefile.close();

	return max;
}
<<<<<<< Updated upstream
=======

//int Maxscore()
//{
//	fstream scorefile;
//	scorefile.open("Savebest.txt", ios::in);
//
//	if (scorefile.fail())
//	{
//		cout << "khong mo duoc fine" << endl;
//		return 0;
//	}
//	int max = 0;
//	string data;
//	while (scorefile.good())
//	{
//		getline(scorefile, data);
//		if ((int)atoi(data.c_str()) > max)
//		{
//			max = (int)atoi(data.c_str());
//		}
//	}
//	scorefile.close();
//
//	return max;
//}
>>>>>>> Stashed changes
