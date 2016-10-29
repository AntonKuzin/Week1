#ifdef JUDGE
#include <fstream>
std::ifstream cin("prepare.in");
std::ofstream cout("prepare.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int abs(int value)
{
	if (value < 0)
	{
		return -value;
	}
	return value;
}

int main() {

	int n;
	cin >> n;

	int* theory = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> theory[i];
	}

	int* practice = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> practice[i];
	}

	int sum = 0;
	bool p = false, t = false;
	int min_difference = 2000;
	for (size_t i = 0; i < n; i++)
	{
		if (theory[i] > practice[i])
		{
			sum += theory[i];
			t = true;
		}
		else
		{
			sum += practice[i];
			p = true;
		}

		if (abs(theory[i] - practice[i]) < min_difference)
		{
			min_difference = abs(theory[i] - practice[i]);
		}
	}

	if (!p || !t)
	{
		sum -= min_difference;
	}

	cout << sum << std::endl;

	return 0;
}

