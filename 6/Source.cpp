#ifdef JUDGE
#include <fstream>
std::ifstream cin("template.in");
std::ofstream cout("template.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>


#define GetMax(a, b) ((a) > (b) ? (a) : (b))

int GetDist(int Xa, int Xb, int Ya, int Yb)
{
	return GetMax(abs(Xa - Xb), abs(Ya - Yb));
}

int GetY(char symbol, std::vector< std::string > keyboard)
{
	for (size_t i = 0; i < keyboard.capacity(); i++)
	{
		if (keyboard[i].find(symbol) != std::string::npos)
		{
			return ++i;
		}
	}
	return -1;
}

int GetX(char symbol, std::string str)
{
	return str.find(symbol) + 1;
}

int main() {

	int width, height;
	std::string str, delimiter = " ";
	std::getline(cin, str);
	width = atoi(str.substr(0, str.find(delimiter)).c_str());
	height = atoi(str.substr(str.find(delimiter) + 1, str.length() - str.find(delimiter)).c_str());

	std::vector< std::string > keyboard(height);

	for (size_t i = 0; i < height; i++)
	{
		std::getline(cin, keyboard[i]);
	}

	std::getline(cin, str);

	std::vector< std::string > langs(3);

	int minDist = 1e6;
	int langNumber;
	for (size_t i = 0; i < 3; i++)
	{
		std::getline(cin, langs[i]);

		std::string tempstr, code;

		do
		{
			std::getline(cin, tempstr);
			if (tempstr == " " || tempstr.empty())
			{
				break;
			}
			code.append(tempstr);
			if (cin.eof())
			{
				break;
			}

		} while (true);

		int lenght = 0;
		for (size_t i = 1; i < code.length(); i++)
		{
			char a = code[i - 1];
			char b = code[i];
			

			int Ya = GetY(a, keyboard);
			int Xa = GetX(a, keyboard[Ya - 1]);
			int Yb = GetY(b, keyboard);
			int Xb = GetX(b, keyboard[Yb - 1]);

			lenght += GetDist(Xa, Xb, Ya, Yb);
			
		}

		if (lenght < minDist)
		{
			minDist = lenght;
			langNumber = i;
		}
	}

	cout << langs[langNumber] << std::endl << minDist << std::endl;

	return 0;
}

