#include <iostream>

using namespace std;

int main(void)
{
	int n;
	long long ans = 1;
	cin >> n;
	for (long long i = 1; i <= n; i++)
		ans += (3 * i + 1) % 45678;

	cout << ans % 45678;
	return 0;
}