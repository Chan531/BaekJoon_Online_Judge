#include <iostream>
#include <queue>
#include <cstring>
#define N 55

using namespace std;

int n, m, t, map[N][N], temp[N][N], c[2], ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void input()
{
	cin >> n >> m >> t;

	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
				c[idx++] = i;
		}
	}
}

void copy()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = temp[i][j];

	map[c[0]][0] = -1;
	map[c[1]][0] = -1;
}

void spread()
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] <= 0)
				continue;

			int cnt = 0;
			int val = map[i][j] / 5;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				// 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
				if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == -1)
					continue;

				temp[ni][nj] += val;
				cnt++;
			}

			temp[i][j] += map[i][j] - val * cnt;
		}
	}

	copy();
}

void clean()
{
	memset(temp, 0, sizeof(temp));

	// 반시계
	for (int i = 0; i < m - 1; i++)
		if (map[c[0]][i] > 0)
			temp[c[0]][i + 1] = map[c[0]][i];

	for (int i = c[0]; i > 0; i--)
		if (map[i][m - 1] > 0)
			temp[i - 1][m - 1] = map[i][m - 1];

	for (int i = m - 1; i > 0; i--)
		if (map[0][i] > 0)
			temp[0][i - 1] = map[0][i];

	for (int i = 0; i < c[0] - 1; i++)
		if (map[i][0] > 0)
			temp[i + 1][0] = map[i][0];

	// 시계
	for (int i = 0; i < m - 1; i++)
		if (map[c[1]][i] > 0)
			temp[c[1]][i + 1] = map[c[1]][i];

	for (int i = c[1]; i < n - 1; i++)
		if (map[i][m - 1] > 0)
			temp[i + 1][m - 1] = map[i][m - 1];

	for (int i = m - 1; i > 0; i--)
		if (map[n - 1][i] > 0)
			temp[n - 1][i - 1] = map[n - 1][i];

	for (int i = n - 1; i > c[1] + 1; i--)
		if (map[i][0] > 0)
			temp[i - 1][0] = map[i][0];

	for (int i = 1; i < c[0]; i++)
		for (int j = 1; j < m - 1; j++)
			temp[i][j] = map[i][j];

	for (int i = c[1] + 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			temp[i][j] = map[i][j];

	copy();
}

void solution()
{
	while (t--)
	{
		spread();
		clean();
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] > 0)
				ans += map[i][j];

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