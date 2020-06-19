#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class StrNumData
{
	static const string data1[9][4];
	static const string S_M[6];
	static const string DecData[10];
	static const string R_K[6];
	static int _Search_(string buff[], int summ,int kopeyki);
public:
	static void Print(string buff[],long summ, int kopeyki)
	{
		int amount = _Search_(buff, summ,kopeyki)-1;
		for (int i = amount; i > -1; --i)
		{
			cout << buff[i]<<" ";
		}
	}
};

