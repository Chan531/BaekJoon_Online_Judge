#include <iostream>

using namespace std;

int gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	unsigned long long a, b;
	cin >> a >> b;
	for (int i = 0; i < gcd(a, b); i++)
		cout << 1;
	return 0;
}