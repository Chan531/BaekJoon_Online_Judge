#include <iostream>
#include <algorithm>
#define N 220

using namespace std;

int n, m, ans = -10001, dp[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int a = 0; a < i; a++)
				for (int b = 0; b < j; b++)
					ans = max(ans, dp[i][j] - dp[a][j] - dp[i][b] + dp[a][b]);

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