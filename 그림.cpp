#include <iostream>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, cnt, ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool map[500][500], visited[500][500];

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
	int pic = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		pic++;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !map[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	ans = max(ans, pic);
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || !map[i][j])
				continue;

			cnt++;
			bfs(i, j);
		}
	}

	cout << cnt << '\n' << ans;
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