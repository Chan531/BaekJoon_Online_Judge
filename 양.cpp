#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, m, sheep, wolf, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[250][250];
bool visited[250][250];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void bfs(int y, int x)
{
	queue<p> q;
	q.push({ y, x });
	visited[y][x] = 1;

	int o = 0, v = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == 'o')
			o++;

		if (map[y][x] == 'v')
			v++;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#' || visited[ny][nx] == 1)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	if (o > v)
		sheep += o;

	else
		wolf += v;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '#' || visited[i][j] == 1)
				continue;

			bfs(i, j);
		}
	}

	cout << sheep << ' ' << wolf;
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