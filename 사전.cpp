#include <iostream>
#include <algorithm>
#include <cstring>
#define N 1e9

using namespace std;

int n, m, k;
int dp[101][101];

void input()
{
	cin >> n >> m >> k;
}

int setdp(int a, int b)
{
	if (a == 0 || b == 0)
		return dp[a][b] = 1;

	if (dp[a][b] != -1)
		return dp[a][b];

	return dp[a][b] = min((int)N, setdp(a - 1, b) + setdp(a, b - 1));
}

void solution()
{
	memset(dp, -1, sizeof(dp));

	if (k > setdp(n, m))
	{
		cout << -1;
		return;
	}

	while (1)
	{
		int acnt = dp[n - 1][m];
		int zcnt = dp[n][m - 1];

		if (!n)
		{
			for (int j = 0; j < m; j++)
				cout << 'z';

			break;
		}

		if (!m)
		{
			for (int j = 0; j < n; j++)
				cout << 'a';

			break;
		}

		if (acnt >= k)
		{
			cout << 'a';
			n--;
			continue;
		}

		if (acnt < k)
		{
			cout << 'z';
			k -= acnt;
			m--;
			continue;
		}
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
	cout.tie(NULL);

	solve();
	return 0;
}