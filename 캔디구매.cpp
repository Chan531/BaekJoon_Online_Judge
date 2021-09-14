#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long c, k;
	cin >> c >> k;
	k = pow(10, k);
	if (c % k >= k / 2)
		cout << (c / k) * k + k;
	else
		cout << c - c % k;
	return 0;
}