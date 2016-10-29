#ifdef JUDGE
#include <fstream>
#include <math.h>
std::ifstream cin("team.in");
std::ofstream cout("team.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main() {

	int arr[3][3];

	for (size_t i = 0; i < 3; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	double sum = 0;
	for (size_t i = 0; i < 3; i++)
	{
		int A = arr[0][i];
		for (size_t j = 0; j < 3; j++)
		{
			int B = arr[1][j];
			for (size_t k = 0; k < 3; k++)
			{
				int C = arr[2][k];
				if (i != j && j != k && i != k)
				{
					double temp = sqrt(A * A + B * B + C * C);
					if (temp > sum)
					{
						sum = temp;
					}
				}
			}
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		int A = arr[i][0];
		for (size_t j = 0; j < 3; j++)
		{
			int B = arr[j][1];
			for (size_t k = 0; k < 3; k++)
			{
				int C = arr[k][2];
				if (i != j && j != k && i != k)
				{
					double temp = sqrt(A * A + B * B + C * C);
					if (temp > sum)
					{
						sum = temp;
					}
				}
			}
		}
	}

	cout.precision(17);
	cout << sum << std::endl;

	return 0;
}

