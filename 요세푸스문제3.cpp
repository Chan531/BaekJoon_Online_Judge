#include <iostream>

using namespace std;

int n, k, a = 1, b;

void solve()
{
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2)
			a = (b + k - 1) % i + 1;
		else
			b = (a + k - 1) % i + 1;
	}
	n % 2 ? cout << a : cout << b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}