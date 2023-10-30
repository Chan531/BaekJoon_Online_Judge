#include <iostream>
#include <algorithm>
#define N 1010

using namespace std;

int n, m, map[N][N], dp[N][N][3], ans = 1e9;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][0] = map[i][j];
			dp[i][j][1] = map[i][j];
			dp[i][j][2] = map[i][j];

			if (j != 1)
				dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);

			else
				dp[i][j][0] = 1e9;


			dp[i][j][1] += min(dp[i - 1][j][0], dp[i - 1][j][2]);

			if (j != m)
				dp[i][j][2] += min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);

			else
				dp[i][j][2] = 1e9;
		}
	}
	
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < 3; j++)
			ans = min(ans, dp[n][i][j]);

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