#include <iostream>
#include <queue>
#define N 1010
#define p pair<int, int>
#define y first
#define x second

using namespace std;

struct node {
	int y, x, cnt, able;
};

int n, m, map[N][N], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
p s, e;
bool visited[N][N][2];

void input()
{
	cin >> n >> m >> s.y >> s.x >> e.y >> e.x;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void solution()
{
	queue<node> q;
	q.push({ s.y, s.x, 0, 1 });
	visited[s.y][s.x][1] = 1;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.y == e.y && cur.x == e.x)
		{
			cout << cur.cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m)
				continue;

			// 벽을 부술 수 없는 상태에 벽이라면 pass
			if (!cur.able && map[ny][nx])
				continue;

			if (map[ny][nx] && !visited[ny][nx][0])
			{
				q.push({ ny, nx, cur.cnt + 1, 0 });
				visited[ny][nx][0] = 1;
			}

			else if (!map[ny][nx] && !visited[ny][nx][cur.able])
			{
				q.push({ ny, nx, cur.cnt + 1, cur.able });
				visited[ny][nx][cur.able] = 1;
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