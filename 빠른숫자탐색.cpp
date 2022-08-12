#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x, cnt;
};

int a, b, ans = -1;
int map[5][5], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
// 0 -> 길, 1 -> 목적지, -1 -> 벽, 2 -> 방문완료 

void input()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];

	cin >> a >> b;
}

void solution()
{
	queue<node> q;
	q.push({ a, b, 0 });

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (map[y][x] == 2)
			continue;

		if (map[y][x] == 1)
		{
			ans = cnt;
			break;
		}

		map[y][x] = 2;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny == 5 || nx < 0 || nx == 5 || map[ny][nx] == 2)
				continue;

			if (map[ny][nx] == -1)
			{
				map[ny][nx] = 2;
				continue;
			}

			q.push({ ny, nx, cnt + 1 });
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