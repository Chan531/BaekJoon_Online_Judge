#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h, ans = -1;
int tomato[101][101][101], dir[6][3] = { {0, -1, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {-1, 0, 0}, {1, 0, 0} };

struct Node
{
	int z, y, x;
};

queue<Node> q;

void input()
{
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
				cin >> tomato[i][j][k];
		}
	}
}

void check()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (tomato[i][j][k] == 0)
				{
					cout << -1;
					return;
				}
				ans = max(ans, tomato[i][j][k]);
			}
		}
	}
	cout << ans - 1;
}

void bfs()
{
	while (!q.empty())
	{
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dir[i][0];
			int ny = y + dir[i][1];
			int nx = x + dir[i][2];

			if (nz <= 0 || nz > h || ny <= 0 || ny > n || nx <= 0 || nx > m)
				continue;

			if (tomato[nz][ny][nx] == 0)
			{
				tomato[nz][ny][nx] = tomato[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}
	check();
}

void solution()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (tomato[i][j][k] == 1)
					q.push({ i, j, k });
			}
		}
	}
	bfs();
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