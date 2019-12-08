#include "File.h"


void SaveToFile(int scoreplayer, int scorecomputer)
{
	fstream savefile;
	savefile.open("Save.txt", ios::out);

	savefile << scoreplayer << endl;
	savefile << scorecomputer << endl;

	savefile.close();
}

void LoadFile(char mode, int &scoreplayer, int & scorecomputer)
{
	fstream loadfile;

	if (mode == '1')
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

}
