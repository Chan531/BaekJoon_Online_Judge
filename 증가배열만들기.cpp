#include <iostream>

using namespace std;

int n, m, k;

void input()
{
	cin >> n >> m >> k;
}

void solution()
{
	if (n + m - 1 > k)
	{
		cout << "NO";
		return;
	}

	cout << "YES\n";

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << i + j << ' ';

		cout << '\n';
	}
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