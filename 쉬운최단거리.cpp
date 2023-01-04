#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node {
	int y, x, dis;
};

int n, m;
int map[1000][1000], ans[1000][1000], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
queue<node> q;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				q.push({ i, j, 0 });
		}
	}
}

void solution()
{
	memset(ans, -1, sizeof(ans));

	ans[q.front().y][q.front().x] = 0;

	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int curdis = q.front().dis;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexty = cury + dir[i][0];
			int nextx = curx + dir[i][1];

			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m || ans[nexty][nextx] != -1 || map[nexty][nextx] == 0)
				continue;

			ans[nexty][nextx] = curdis + 1;
			q.push({ nexty, nextx, curdis + 1 });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				ans[i][j] = 0;

			cout << ans[i][j] << ' ';
		}

		cout << '\n';
	}
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