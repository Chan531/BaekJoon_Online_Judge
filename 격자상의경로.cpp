#include <iostream>
#include <vector>

using namespace std;

int n, m, k, x, y, dp[16][16], ans = 0;

void input()
{
	cin >> n >> m >> k;
}

void setxy()
{
	if (k != 0)
	{
		if (k % m)
		{
			x = k % m;
			y = k / m + 1;
		}

		else
		{
			x = m;
			y = k / m;
		}
	}

	else
	{
		x = m;
		y = n;
	}
}

void solution()
{
	setxy();

	for (int i = 1; i <= y; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			if (i == 1 || j == 1)
			{
				dp[i][j] = 1;
				continue;
			}

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	if (x != m || y != n)
	{
		ans = dp[y][x];

		for (int i = y; i <= n; i++)
		{
			for (int j = x; j <= m; j++)
			{
				if (i == y || j == x)
				{
					dp[i][j] = 1;
					continue;
				}

				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	ans != 0 ? cout << ans * dp[n][m] : cout << dp[n][m];
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