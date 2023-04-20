#include <iostream>

using namespace std;

int n, m, k;

void input()
{
	cin >> n >> m >> k;
}

void solution()
{
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		k -= b;

		if (k < 0)
		{
			cout << i << ' ' << 1;
			return;
		}
	}

	cout << -1;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}