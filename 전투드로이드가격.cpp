#include <iostream>

using namespace std;

int main(void)
{
	int n, a, b, c, d, e;
	double A = 350.34, B = 230.9, C = 190.55, D = 125.3, E = 180.9;
	cin >> n;
	cout << fixed;
	cout.precision(2);
	while (n--)
	{
		cin >> a >> b >> c >> d >> e;
		cout << '$' << a * A + b * B + c * C + d * D + e * E << '\n';
	}
	return 0;
}