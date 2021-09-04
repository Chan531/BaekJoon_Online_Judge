#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, d, e, s = 0;
	cin >> a >> b >> c >> d >> e;
	if (b - a > b)
	{
		s += c * (a * -1) + d + e * b;
	}
	else
	{
		s += (b - a) * e;
	}
	cout << s;
	return 0;
}