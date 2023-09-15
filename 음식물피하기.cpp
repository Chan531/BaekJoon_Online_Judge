#include <iostream>
#include <queue>
#include <algorithm>
#define N 110
#define p pair<int, int>
#define y first
#define x second

using namespace std;

int n, m, k, ans, map[N][N], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[N][N];

void input()
{
	cin >> n >> m >> k;

	while (k--)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
}

int bfs(int y, int x)
{
	int ret = 1;
	queue<p> q;
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		p cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m || visited[ny][nx] || !map[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
			ret++;
		}
	}

	return ret;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!map[i][j] || visited[i][j])
				continue;

			ans = max(ans, bfs(i, j));
		}
	}

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