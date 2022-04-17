#include <iostream>

using namespace std;

int main(void)
{
	cout << fixed;
	cout.precision(2);
	double a, b;
	cin >> a;
	while (cin >> b)
	{
		if (b == 999)
			break;

		cout << b - a << '\n';
		a = b;
	}
	return 0;
}