#ifdef JUDGE
#include <fstream>
std::ifstream cin("aplusbb.in");
std::ofstream cout("aplusbb.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main() {
	long long a, b;
	cin >> a >> b;
	cout << a + (b * b) << std::endl;
	return 0;
}