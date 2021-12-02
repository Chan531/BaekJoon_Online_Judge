#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(void)
{
	double r, pi = M_PI;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r * r * pi << '\n' << r * r * 2;
	return 0;
}