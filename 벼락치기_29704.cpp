#include <iostream>
#include <algorithm>
#include <numeric>
#define N 1010

using namespace std;

int n, t, d[N], m[N], dp[N][N];

void input()
{
	cin >> n >> t;

	for (int i = 1; i <= n; i++)
		cin >> d[i] >> m[i];
}

void init()
{
	int sum = accumulate(m, m + n + 1, 0);

	for (int i = 0; i <= t; i++)
		dp[0][i] = sum;
}

void solution()
{
	init();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= t; j++)
		{
			if (j < d[i])
				dp[i][j] = dp[i - 1][j];

			else
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - d[i]] - m[i]);
		}
	}

	cout << dp[n][t];
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