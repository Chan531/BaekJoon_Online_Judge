#include <iostream>

using namespace std;

int tc, n, m, mod = 1000000009;
long long dp[1010][1010];

void input()
{
	cin >> tc;
}

void init()
{
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
}

void solution()
{
	init();

	for (int i = 4; i <= 1000; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1];
			dp[i][j] %= mod;
		}

		dp[i][i] = 1;
	}

	while (tc--)
	{
		cin >> n >> m;
		cout << dp[n][m] << '\n';
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