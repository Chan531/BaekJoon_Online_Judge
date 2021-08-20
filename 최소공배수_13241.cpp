#include <iostream>

using namespace std;


int gcd(int n, int m)
{
	if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

int main(void)
{
	long long int n, m;
	cin >> n >> m;
	cout << n * m / gcd(n, m);
	return 0;
}