#include <iostream>
#include <queue>
#include <algorithm>
#define N 660
#define p pair<int, int>
#define y first
#define x second

using namespace std;

int n, m, ans, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[N][N];
bool visited[N][N];
p s;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'I')
			{
				s.y = i;
				s.x = j;
			}
		}
	}
}

void solution()
{
	queue<p> q;
	q.push(s);
	visited[s.y][s.x] = 1;

	while (!q.empty())
	{
		p cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 'X' || visited[ny][nx])
				continue;

			if (map[ny][nx] == 'P')
				ans++;

			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

	ans ? cout << ans : cout << "TT";
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