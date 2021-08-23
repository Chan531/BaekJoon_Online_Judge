#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	cout << fixed;
	cout.precision(6);
	double k, d1, d2;
	cin >> k >> d1 >> d2;
	if (d1 == d2)
		cout << pow(k, 2);
	else
		cout << pow(k, 2) - pow((d1 - d2) / 2, 2);
	return 0;
}