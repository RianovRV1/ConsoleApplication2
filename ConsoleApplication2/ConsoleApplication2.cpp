// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;
const int TOTAL_TILE_SPRITES = 4; 
string FillNumber(int num);
void WriteToMap(string fileName, int height, int width);
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int x, y;
	x = 0;
	y = 0;
	string FileName = "map.map";
	stringstream SubFileName;
	SubFileName << x << y;
	FileName.insert(3, SubFileName.str());
	cout << FileName << endl;

	string line;
	WriteToMap(FileName, 10, 16);
	ifstream file2(FileName);
	if (file2.is_open())
	{
		while (getline(file2, line))
		{
			cout << line << '\n';
		}
		file2.close();
	}
	remove(FileName.c_str());
	system("PAUSE");
	return 0;
}

string FillNumber(int num)
{
	stringstream fill;
	fill << setfill('0') << std::setw(2) << num;
	return fill.str();
}

void WriteToMap(string fileName, int height, int width)
{
	int wallLimit = (((height*width) - (2 * (height - 2)) + (2 * width)) / 4);
	ofstream file(fileName);
	for (int i = 0; i < height; ++i)
	{
		int toLimit = 0;
		for (int j = 0; j < width; ++j)
		{
			
			if (i == 0 && j == (width / 2))// up
				file << FillNumber(0) << " ";
			else if (i == (height / 2) && j == (0)) // left
				file << FillNumber(1) << " ";
			else if (i == (height - 1) && j == (width / 2)) // down
				file << FillNumber(3) << " ";
			else if (i == height / 2 && j == (width - 1)) //right
				file << FillNumber(2) << " ";
			else if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1) && (i != (height / 2) || j != (width / 2)))//wall
			{
				file << FillNumber(4) << " ";
			}

			else//rest of floor
			{
				int num = rand() % TOTAL_TILE_SPRITES + 4;
				if (num == 4 && toLimit < wallLimit)
				{
					file << FillNumber(num) << " ";
					++toLimit;
				}
				else if (num == 4 && toLimit >= wallLimit)
				{
					num = (rand() % (TOTAL_TILE_SPRITES - 1)) + 5;
					file << FillNumber(num) << " ";
				}
				else
				{
					file << FillNumber(num) << " ";
				}
			}
		}
		file << "\n";
	}
	file.close();
}