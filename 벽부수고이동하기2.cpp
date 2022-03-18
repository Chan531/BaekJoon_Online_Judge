#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, dp[1001][1001][11], dir[4][2] = { {-1, 0},{0, 1},{1,0},{0,-1} }, ans = 1000001;
char map[1001][1001];

struct node {
	int y, x, cnt;
};

void input()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void solution()
{
	queue<node> q;
	q.push({ 1, 1, 0 });
	dp[1][1][0] = 1;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m)
				continue;

			if (map[ny][nx] == '0' && !dp[ny][nx][cnt])
			{
				dp[ny][nx][cnt] = dp[y][x][cnt] + 1;
				q.push({ ny, nx, cnt });
			}

			if (map[ny][nx] == '1' && cnt != k && !dp[ny][nx][cnt + 1])
			{
				dp[ny][nx][cnt + 1] = dp[y][x][cnt] + 1;
				q.push({ ny, nx, cnt + 1 });
			}
		}
	}
	for (int i = 0; i <= k; i++)
	{
		if (dp[n][m][i])
			ans = min(ans, dp[n][m][i]);
	}
	ans == 1000001 ? cout << -1 : cout << ans;
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