#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	a += c / 60;
	b += c % 60;
	if (b >= 60)
	{
		a += b / 60;
		b = b % 60;
	}
	if (a >= 24)
		a = a % 24;
	cout << a << ' ' << b;
	return 0;
}