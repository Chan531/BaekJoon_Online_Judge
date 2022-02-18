#include <iostream>

using namespace std;

int n, m;

void solve()
{
	cin >> n;

	if (n == 1 || n == 3)
	{
		cout << -1;
		return;
	}

	for (int i = n / 5; i >= 0; i--)
	{
		m = n - i * 5;
		if (!(m % 2))
		{
			cout << i + m / 2;
			break;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}