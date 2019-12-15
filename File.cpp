#include "File.h"


void SaveToFile(int scoreplayer, int scorecomputer, vector<playerInfor> listPlayer)
{
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
	fstream savefile;
	savefile.open("Save.txt", ios::out);

	savefile << scoreplayer << endl;
	savefile << scorecomputer << endl;

	for (int i = 0; i < listPlayer.size()  && savefile.is_open(); i++)
	{
		savefile << listPlayer[i].name << endl << listPlayer[i].score << endl;
	}

	savefile.close();
}

void LoadFile(char mode, int &scoreplayer, int & scorecomputer, vector<playerInfor> &list)
{
	fstream loadfile;
	loadfile.open("Save.txt", ios::in);
	string lineTemp;

<<<<<<< Updated upstream
	if (mode == '1')
=======
	if (loadfile.fail())
	{
		cout << "ban chua luu game" << endl;
	}
	list.clear();
	if (mode == '2')
>>>>>>> Stashed changes
	{
		scoreplayer = 0;
		scorecomputer = 0;
		getline(loadfile, lineTemp);//bo qua dong diem computer
		getline(loadfile, lineTemp);//bo qua dong diem you
	}
	else
	{
		
		loadfile >> scoreplayer;
		loadfile >> scorecomputer;
		
	}
	playerInfor temp;
	string line;

<<<<<<< Updated upstream
}
=======
	while (!loadfile.eof())
	{
		do
		{
			getline(loadfile, line);
		} while (line.empty() && !loadfile.eof());

		if (!line.empty())
		{
			temp.name = line;
			getline(loadfile, line);
			temp.score = tryParseInt(line);
			list.push_back(temp);
		}


	}
	loadfile.close();

}

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
