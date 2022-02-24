#include <iostream>
#include <vector>

using namespace std;

int n, map[33][33], diag[3][2] = { {0, 1},{1, 0},{1,1} };
long long dp[33][33][3];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
}

long long dfs(int y, int x, int status)
{
	if (y == n && x == n)
		return 1;

	if (dp[y][x][status])
		return dp[y][x][status];

	if (status == 1)
	{
		if (y >= 0 && y <= n && x >= 0 && x < n && !map[y][x + 1])
			dp[y][x][status] += dfs(y, x + 1, status);

		for (int i = 0; i < 3; i++)
		{
			int ny = y + diag[i][0];
			int nx = x + diag[i][1];

			if (ny < 0 || ny > n || nx < 0 || nx > n || map[ny][nx])
				break;

			if (i == 2)
				dp[y][x][status] += dfs(ny, nx, 3);
		}
	}

	if (status == 2)
	{
		if (y >= 0 && y < n && x >= 0 && x <= n && !map[y + 1][x])
			dp[y][x][status] += dfs(y + 1, x, status);

		for (int i = 0; i < 3; i++)
		{
			int ny = y + diag[i][0];
			int nx = x + diag[i][1];

			if (ny < 0 || ny > n || nx < 0 || nx > n || map[ny][nx])
				break;

			if (i == 2)
				dp[y][x][status] += dfs(ny, nx, 3);
		}
	}

	if (status == 3)
	{
		if (y >= 0 && y <= n && x >= 0 && x < n && !map[y][x + 1])
			dp[y][x][status] += dfs(y, x + 1, 1);

		if (y >= 0 && y < n && x >= 0 && x <= n && !map[y + 1][x])
			dp[y][x][status] += dfs(y + 1, x, 2);

		for (int i = 0; i < 3; i++)
		{
			int ny = y + diag[i][0];
			int nx = x + diag[i][1];

			if (ny < 0 || ny > n || nx < 0 || nx > n || map[ny][nx])
				break;

			if (i == 2)
				dp[y][x][status] += dfs(ny, nx, status);
		}
	}

	return dp[y][x][status];
}

void solution()
{
	cout << dfs(1, 2, 1);
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