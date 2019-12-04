#include "File.h"


void SaveToFile(int scoreplayer, int scorecomputer)
{
	fstream savefile;
	savefile.open("Save.txt", ios::out);

	savefile << scoreplayer << endl;
	savefile << scorecomputer << endl;

	savefile.close();
}

vector<int> LoadFile()
{
	vector<int>temp;
	fstream loadfile;

	temp.push_back(0);
	temp.push_back(0);

	loadfile.open("Save.txt", ios::in);

	if (loadfile.fail())
	{
		cout << "ban chua luu game" << endl;
		return temp;
	}

	string token;
	int i = 0;
	while (loadfile.good())
	{
		getline(loadfile, token);
		temp.push_back((int)atoi(token.c_str()));
	}
	loadfile.close();

	return temp;
}
