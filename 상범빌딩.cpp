#include <iostream>
#include <queue>
#include <cstring>
#define N 33

using namespace std;

struct node {
	int x, y, z, cnt;
};

int n, m, k, ans;
node dir[6] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {-1, 0, 0}, {1, 0, 0} };
char map[N][N][N];
bool visited[N][N][N];
node s;

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int l = 0; l < k; l++)
			{
				cin >> map[i][j][l];

				if (map[i][j][l] == 'S')
					s = { i, j, l, 0 };
			}
		}
	}
}

void solution()
{
	queue<node> q;
	q.push(s);
	memset(visited, 0, sizeof(visited));
	visited[s.x][s.y][s.z] = 1;
	ans = -1;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (map[cur.x][cur.y][cur.z] == 'E')
		{
			ans = cur.cnt;
			break;
		}

		for (int i = 0; i < 6; i++)
		{
			int nx = cur.x + dir[i].x;
			int ny = cur.y + dir[i].y;
			int nz = cur.z + dir[i].z;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= k || visited[nx][ny][nz] || map[nx][ny][nz] == '#')
				continue;

			q.push({ nx, ny, nz, cur.cnt + 1 });
			visited[nx][ny][nz] = 1;
		}
	}

	if (ans == -1)
		cout << "Trapped!\n";

	else
		cout << "Escaped in " << ans << " minute(s).\n";
}

void solve()
{
	while (1)
	{
		input();

		if (n == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}