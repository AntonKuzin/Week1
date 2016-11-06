#define JUDGE1
#ifdef JUDGE
#include <fstream>
std::ifstream cin("win.in");
std::ofstream cout("win.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <math.h>
#include <vector>
#include <algorithm>

void BubbleSort(int *arr, int size)
{
	int newn;
	do
	{
		newn = 0;
		for (size_t j = 1; j < size; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				newn = j;
			}
		}
		size = newn;
	} while (newn > 0);

}

int main() {
	int N, limit = 300 * 60;
	cin >> N;

	int* times = new int[N];
	for (size_t i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		times[i] = temp;
	}
	
	BubbleSort(times, N);

	int count = 0, currentSum = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (currentSum + times[i] <= limit)
		{
			currentSum += times[i];
			count++;
		}
		else
			break;
	}
	
	cout << count << std::endl;
	return 0;
}

