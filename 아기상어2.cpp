#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, map[50][50], ans;
bool visited[50][50];
int dir[8][2] = { {-1, -1},{-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1},{0, -1} };

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
	queue<node> q;
	q.push({ y, x, 0 });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dis = q.front().dis;
		q.pop();

		if (map[y][x])
			return dis;

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
				continue;

			q.push({ ny, nx, dis + 1 });
			visited[ny][nx] = 1;
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
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