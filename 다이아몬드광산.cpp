#include <iostream>
#include <cstring>
#include <algorithm>
#define N 757

using namespace std;

int n, m, ans = -1, dp[N][N][4], dir[4][2] = { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} };
char map[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int check(int y, int x, int idx)
{
	int ret = -1;

	while (1)
	{
		if (y < 0 || y >= n || x < 0 || x >= m || map[y][x] == '0') break;

		if (dp[y][x][idx] != -1)
		{
			ret = dp[y][x][idx] + 1;
			break;
		}

		ret++;
		y += dir[idx][0];
		x += dir[idx][1];
	}

	return ret;
}

void dia(int y, int x)
{
	// ╩С
	int val = min(dp[y][x][2], dp[y][x][3]);

	while (ans < val)
	{
		if (dp[y + val][x - val][2] >= val && dp[y + val][x + val][3] >= val)
		{
			ans = max(ans, val);
			break;
		}

		val--;
	}

	// ©Л
	val = min(dp[y][x][0], dp[y][x][3]);

	while (ans < val)
	{
		if (dp[y - val][x - val][3] >= val && dp[y + val][x - val][0] >= val)
		{
			ans = max(ans, val);
			break;
		}

		val--;
	}

	// го
	val = min(dp[y][x][0], dp[y][x][1]);

	while (ans < val)
	{
		if (dp[y - val][x - val][1] >= val && dp[y - val][x + val][0] >= val)
		{
			ans = max(ans, val);
			break;
		}

		val--;
	}

	// аб
	val = min(dp[y][x][1], dp[y][x][2]);

	while (ans < val)
	{
		if (dp[y - val][x + val][2] >= val && dp[y + val][x + val][1] >= val)
		{
			ans = max(ans, val);
			break;
		}

		val--;
	}
}

void solution()
{
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++)
				dp[i][j][k] = check(i, j, k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '0') continue;
			dia(i, j);
		}
	}

	cout << ans + 1;
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