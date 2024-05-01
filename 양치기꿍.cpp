#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, m, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
p ans;
char map[255][255];
bool visited[255][255];

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
	int v = 0, k = 0;

	while (!q.empty())
	{
		p cur = q.front();
		q.pop();

		if (map[cur.first][cur.second] == 'v')
			v++;

		else if (map[cur.first][cur.second] == 'k')
			k++;

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dir[i][0];
			int nx = cur.second + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#' || visited[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	(k > v) ? ans.first += k : ans.second += v;
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] != '#' && !visited[i][j])
				bfs(i, j);

	cout << ans.first << ' ' << ans.second;
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