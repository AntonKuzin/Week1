#define JUDGE1
#ifdef JUDGE
#include <fstream>
std::ifstream cin("testgen.in");
std::ofstream cout("testgen.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <math.h>
#include <vector>

std::vector<int> FillWithPrimes(int limit)
{
	std::vector<int> primes;

	for (size_t i = 2; i <= limit; i++)
	{
		bool isPrime = true;

		for (size_t j = 0; j < primes.size(); j++)
		{
			if (i % primes[j] == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			primes.push_back(i);
		}
	}
	return primes;
}

int main() {

	int K;
	cin >> K;

	int upperPrimeLimit = ceil(sqrt(K));

	std::vector<int> primes = FillWithPrimes(upperPrimeLimit);
		

	std::vector<int> primeFactorisation;
	int primeIndex = 0;
	int temp = K;
	while (temp > 1)
	{
		if (primeIndex > primes.size() - 1)
		{
			primeFactorisation.push_back(temp);
			break;
		}

		while (temp % primes[primeIndex] == 0)
		{
			primeFactorisation.push_back(primes[primeIndex]);
			temp /= primes[primeIndex];
		}
		primeIndex++;
		
	}

	for each (int value in primeFactorisation)
	{
		cout << value << " ";
	}
	

	cout << std::endl;

	return 0;
}

