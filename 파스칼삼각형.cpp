#include <iostream>

using namespace std;

int n, m, k, ans, dp[33][33];

void input()
{
	cin >> n >> m >> k;
}

void init()
{
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	for (int i = 3; i <= 30; i++)
	{
		dp[i][1] = 1;
		dp[i][i] = 1;

		for (int j = 2; j < i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}
}

void solution()
{
	init();

	int idx = 0;

	for (int i = n; i < n + k; i++)
	{
		for (int j = 0; j <= idx; j++)
		{
			ans += dp[i][m + j];
		}

		idx++;
	}

	cout << ans;
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