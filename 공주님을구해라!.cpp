#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m, t, map[101][101], ans = 1e9;
int dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };
bool visited[101][101];

struct node {
	int y, x, dis;
};

void input()
{
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void solution()
{
	queue<node> q;
	q.push({ 1, 1, 0 });
	visited[1][1] = 1;

	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int dis = q.front().dis;
		q.pop();

		if (dis > t)
			break;

		if (cury == n && curx == m)
		{
			ans = min(ans, dis);
			break;
		}

		if (map[cury][curx] == 2)
		{
			ans = min(ans, dis + abs(cury - n) + abs(curx - m));

			if (ans > t)
				ans = 1e9;

			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nexty = cury + dir[i][0];
			int nextx = curx + dir[i][1];

			if (!nexty || nexty > n || !nextx || nextx > m || visited[nexty][nextx] || map[nexty][nextx] == 1)
				continue;

			visited[nexty][nextx] = 1;
			q.push({ nexty, nextx, dis + 1 });
		}
	}

	ans == 1e9 ? cout << "Fail" : cout << ans;
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