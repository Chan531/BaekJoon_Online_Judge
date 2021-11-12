#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int l, r, s = 0, i = 1;
	cin >> l >> r;
	l *= r;
	l /= 100;
	while (l > 5)
	{
		s += pow(2, i++) * l;
		l *= r;
		l /= 100;
	}
	cout << s;
	return 0;
}