#include <iostream>
#include <queue>
#define N 1010
#define p pair<int, int>
#define y first
#define x second

using namespace std;

struct node {
	int y, x, cnt, fish;
};

int n, m, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[N][N];
bool visited[N][N][2];
p s, e;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'S')
				s.y = i, s.x = j;

			if (map[i][j] == 'H')
				e.y = i, e.x = j;
		}
	}
}

void solution()
{
	queue<node> q;
	q.push({ s.y, s.x, 0, 0 });
	visited[s.y][s.x][0] = 1;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.y == e.y && cur.x == e.x && cur.fish)
		{
			cout << cur.cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m || map[ny][nx] == 'D')
				continue;

			if (map[ny][nx] == 'F' && !visited[ny][nx][1])
			{
				q.push({ ny, nx, cur.cnt + 1, 1 });
				visited[ny][nx][1] = 1;
			}

			else if (!visited[ny][nx][cur.fish])
			{
				q.push({ ny, nx, cur.cnt + 1, cur.fish });
				visited[ny][nx][cur.fish] = 1;
			}
		}
	}

	cout << -1;
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