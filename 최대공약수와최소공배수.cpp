#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int n = b;
		b = a % b;
		a = n;
	}
	return a;
}

int main(void)
{
	int n, m, k;
	cin >> n >> m;
	if (n > m)
		k = gcd(n, m);
	else
		k = gcd(m, n);
	cout << k << ' ' << n * m / k;
	return 0;
}