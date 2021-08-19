#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int n = a % b;
	a = b;
	b = n;
	return gcd(a, b);
}

int main(void)
{
	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		int minmul = gcd(a, b);
		cout << a * b / minmul << '\n';
	}
	return 0;
}