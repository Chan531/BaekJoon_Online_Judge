#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, dir[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };
int a, b, c, d;
int map[200][200];

void input()
{
	cin >> n >> a >> b >> c >> d;
}

void solution()
{
	if (a == c && b == d)
	{
		cout << 0;
		return;
	}

	queue<p> q;
	q.push({ a, b });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		int val = map[y][x];
		q.pop();

		if (y == c && x == d)
			break;

		for (int i = 0; i < 6; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx])
				continue;

			map[ny][nx] = val + 1;
			q.push({ ny, nx });
		}
	}

	map[c][d] ? cout << map[c][d] : cout << -1;
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