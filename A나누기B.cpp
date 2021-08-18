#include <iostream>

using namespace std;

int main(void)
{
	cout << fixed;
	cout.precision(16);
	double a, b;
	cin >> a >> b;
	cout << a / b + 1e-10;
	return 0;
}