#include <iostream>
#include <queue>
#define N 101
#define p pair<int, int>
#define y first
#define x second

using namespace std;

int n, m, ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[N][N];
bool visited[N][N];

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

	while (!q.empty())
	{
		p cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == '.')
				continue;

			q.push({ ny, nx });
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
			if (visited[i][j] || map[i][j] == '.')
				continue;

			bfs(i, j);
			ans++;
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