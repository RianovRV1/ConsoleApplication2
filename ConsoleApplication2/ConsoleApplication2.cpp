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
void WriteToMap(int height, int width);
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	string line;
	WriteToMap(10, 16);
	ifstream file2("map.map");
	if (file2.is_open())
	{
		while (getline(file2, line))
		{
			cout << line << '\n';
		}
		file2.close();
	}
	remove("map.map");
	system("PAUSE");
	return 0;
}

string FillNumber(int num)
{
	stringstream fill;
	fill << setfill('0') << std::setw(2) << num;
	return fill.str();
}

void WriteToMap(int height, int width)
{
	int wallLimit = (((2 * (height - 2)) + (2 * width)) / 4);
	ofstream file("map.map");
	for (int i = 0; i < height; ++i)
	{
		int toLimit = 0;
		for (int j = 0; j < width; ++j)
		{
			
			if ((i == (height / 2) && (j == 0 || j == (width - 1))) || (j == (width / 2) && (i == 0 || i == (height - 1))))
			{
				file << FillNumber(1) << " ";
			}
			else if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1) && (i != (height / 2) || j != (width / 2)))
			{
				file << FillNumber(0) << " ";
			}

			else
			{
				int num = rand() % TOTAL_TILE_SPRITES;
				if (num == 0 && toLimit != wallLimit)
				{
					file << FillNumber(num) << " ";
					++toLimit;
				}
				else if (num == 0 && toLimit == wallLimit)
				{
					num = (rand() % (TOTAL_TILE_SPRITES - 1)) + 1;
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