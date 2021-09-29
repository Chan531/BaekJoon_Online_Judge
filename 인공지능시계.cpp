#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, d, e = 60;
	cin >> a >> b >> c >> d;
	c += d;
	b += c / e;
	c %= e;
	a += b / e;
	b %= e;
	cout << a % 24 << ' ' << b << ' ' << c;
	return 0;
}