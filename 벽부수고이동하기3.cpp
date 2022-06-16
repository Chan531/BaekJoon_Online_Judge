#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, ans = 1e9;

struct node {
	int y, x, cnt, day;
	// y값, x값, 벽을 부신 개수, 낮밤 상태
};

char map[1000][1000];
int dp[1000][1000][11][2], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
// y, x, 벽을 부신 개수, 0 -> 밤, 1 -> 낮

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	// dp 테이블 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int a = 0; a <= k; a++)
				for (int b = 0; b < 2; b++)
					dp[i][j][a][b] = 1e9;

	queue<node> q;
	q.push({ 0, 0, 0, 1 });
	dp[0][0][0][1] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int day = q.front().day;
		int val = dp[y][x][cnt][day];
		q.pop();

		if (y == n - 1 && x == m - 1)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)                    // 범위 벗어났으면 pass
				continue;

			if (map[ny][nx] == '1' && cnt < k)                            // 이동하려하는 곳이 벽이고 아직 벽을 더 부실 수 있을 때
			{
				if (day == 1 && val + 1 < dp[ny][nx][cnt + 1][0])          // 만약 낮이라면 (벽은 낮에만 부실 수 있음)
				{
					dp[ny][nx][cnt + 1][0] = val + 1;
					q.push({ ny, nx, cnt + 1, 0 });
				}
			}

			if (map[ny][nx] == '0')                                        // 이동하려하는 곳이 벽이 아닐 때
			{
				if (day == 0 && val + 1 < dp[ny][nx][cnt][1])              // 만약 밤이라면
				{
					dp[ny][nx][cnt][1] = val + 1;
					q.push({ ny, nx, cnt, 1 });
				}

				if (day == 1 && val + 1 < dp[ny][nx][cnt][0])              // 만약 낮이라면
				{
					dp[ny][nx][cnt][0] = val + 1;
					q.push({ ny, nx, cnt, 0 });
				}
			}
		}

		// 제자리에 가만히 있는 경우
		if (day == 0 && val + 1 < dp[y][x][cnt][1])
		{
			dp[y][x][cnt][1] = val + 1;
			q.push({ y, x, cnt, 1 });
		}

		if (day == 1 && val + 1 < dp[y][x][cnt][0])
		{
			dp[y][x][cnt][0] = val + 1;
			q.push({ y, x, cnt, 0 });
		}
	}
	
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < 2; j++)
			ans = min(ans, dp[n - 1][m - 1][i][j]);

	ans == 1e9 ? cout << -1 : cout << ans;
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