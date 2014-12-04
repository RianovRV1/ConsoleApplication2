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

string FillNumber(int num);
void WriteToMap();
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	string line;
	WriteToMap();
	ifstream file2("map.map");
	if (file2.is_open())
	{
		while (getline(file2, line))
		{
			cout << line << '\n';
		}
		file2.close();
	}
	system("PAUSE");
	return 0;
}

string FillNumber(int num)
{
	stringstream fill;
	fill << setfill('0') << std::setw(2) << num;
	return fill.str();
}

void WriteToMap()
{
	ofstream file("map.map");
	for (int i = 0; i < 12; ++i)
	{

		for (int j = 0; j < 16; ++j)
		{
			int num = rand() % 12;
			file << FillNumber(num) << " ";
		}
		file << "\n";
	}
	file.close();
}