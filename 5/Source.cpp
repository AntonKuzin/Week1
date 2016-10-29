#ifdef JUDGE
#include <fstream>
#include <math.h>
std::ifstream cin("chairs.in");
std::ofstream cout("chairs.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main() {

	double A, B, C;
	cin >> A >> B >> C;

	double alpha = acos((A*A - B*B - C*C) / (-2 * B * C));
	double beta = acos((B*B - A*A - C*C) / (-2 * A * C));

	double Xa = A / 2 * cos(beta);
	double Ya = A / 2 * sin(beta);
	double Xb = C - B / 2 * cos(alpha);
	double Yb = B / 2 * sin(alpha);
	double Xc = C / 2;
	double Yc = 0;

	double AB = sqrt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb));
	double AC = sqrt((Xa - Xc) * (Xa - Xc) + (Ya - Yc) * (Ya - Yc));
	double BC = sqrt((Xc - Xb) * (Xc - Xb) + (Yc - Yb) * (Yc - Yb));

	double avg = (AB + AC + BC) / 3;

	cout.precision(8);
	cout << avg << std::endl;

	return 0;
}

