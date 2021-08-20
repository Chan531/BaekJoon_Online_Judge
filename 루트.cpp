#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int b, n;
	while (1)
	{
		cin >> b >> n;
		if (b == 0 && n == 0)
			break;
		int a = 1;
		while (b > pow(a, n))
			a++;
		abs(b - pow(a, n)) > abs(b - pow(a - 1, n)) ? cout << a - 1 << '\n' : cout << a << '\n';
	}
	return 0;
}