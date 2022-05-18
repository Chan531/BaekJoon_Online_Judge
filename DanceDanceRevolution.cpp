#include <iostream>
#include <algorithm>

using namespace std;

int num, idx = 1, arr[100001], dir[5][5], ans = 1e9;
int dp[100001][5][5];
// idx, 왼발, 오른발

void input()
{
	while (1)
	{
		cin >> num;

		if (num == 0)
			break;

		arr[idx++] = num;
	}
}

void setdir()
{
	for (int i = 0; i < 5; i++)
	{
		dir[i][i] = 1;

		if (i > 0)
		{
			dir[0][i] = 2;
			dir[i][0] = 2;

			for (int j = 1; j < 5; j++)
			{
				if (i == j)
					continue;

				if (i % 2 == j % 2)
				{
					dir[i][j] = 4;
					dir[j][i] = 4;
				}

				else
				{
					dir[i][j] = 3;
					dir[j][i] = 3;
				}
			}
		}
	}
}

void solution()
{
	setdir();

	dp[1][arr[1]][0] = 2;
	dp[1][0][arr[1]] = 2;

	for (int i = 2; i < idx; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (!dp[i - 1][j][k])
					continue;

				// 왼발로 이동
				if (dp[i][arr[i]][k])
					dp[i][arr[i]][k] = min(dp[i][arr[i]][k], dp[i - 1][j][k] + dir[j][arr[i]]);

				else
					dp[i][arr[i]][k] = dp[i - 1][j][k] + dir[j][arr[i]];

				// 오른발로 이동
				if (dp[i][j][arr[i]])
					dp[i][j][arr[i]] = min(dp[i][j][arr[i]], dp[i - 1][j][k] + dir[k][arr[i]]);

				else
					dp[i][j][arr[i]] = dp[i - 1][j][k] + dir[k][arr[i]];
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (!dp[idx - 1][i][j])
				continue;

			ans = min(ans, dp[idx - 1][i][j]);
		}
	}

	ans != 1e9 ? cout << ans : cout << 0;
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