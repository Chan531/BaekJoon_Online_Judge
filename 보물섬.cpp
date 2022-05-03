#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, visited[50][50], ans = 0;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[50][50];

struct node {
	int y, x, dis;
};

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int bfs(int y, int x)
{
	int dis = 0;
	queue<node> q;
	q.push({ y,x,0 });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int curdis = q.front().dis;
		q.pop();

		dis = max(dis, curdis);

		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == 'W')
				continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx, dis + 1 });
		}
	}

	return dis;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				ans = max(ans, bfs(i, j));
				memset(visited, 0, sizeof(visited));
			}
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
	cout.tie(NULL);

	solve();
	return 0;
}