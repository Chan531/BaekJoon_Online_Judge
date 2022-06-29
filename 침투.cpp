#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, m, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[1000][1000];
string ans = "NO";

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	queue<p> q;

	for (int i = 0; i < m; i++)
		if (map[0][i] == '0')
			q.push({ 0, i });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == n - 1)
		{
			ans = "YES";
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny >= n || ny < 0 || nx >= m || nx < 0 || map[ny][nx] == '1')
				continue;

			map[ny][nx] = '1';
			q.push({ ny, nx });
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
	cout.tie(NULL);

	solve();
	return 0;
}