#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	cout << fixed;
	cout.precision(20);
	double a, b;
	cin >> a >> b;

	double ans = 1 / (1 + pow(10, (b - a) / 400));
	cout << ans;
	return 0;
}