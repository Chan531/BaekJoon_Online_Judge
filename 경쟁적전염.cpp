#include <iostream>
#include <queue>
#define N 202
#define p pair<int, int>

using namespace std;

struct node {
	int y, x, cnt;
};

int n, k, s, x, y, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
p map[N][N];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j].first;
			
			if (!map[i][j].first)
				map[i][j].second = 1e9;
		}
	}

	cin >> s >> x >> y;
}

void bfs(int i, int j)
{
	int num = map[i][j].first;
	queue<node> q;
	q.push({ i, j, 0 });

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];
			int ncnt = cur.cnt + 1;

			// 맵 벗어난다면 pass
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;

			// 다른 바이러스가 먼저 퍼져있다면 pass
			if (map[ny][nx].second < ncnt)
				continue;

			// 다른 바이러스와 같은 시간에 도착하지만 그 바이러스보다 번호가 크거나 같다면 pass
			if (map[ny][nx].second == ncnt && map[ny][nx].first <= num)
				continue;

			q.push({ ny, nx, ncnt });
			map[ny][nx].first = num;
			map[ny][nx].second = ncnt;
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j].first && !map[i][j].second)
				bfs(i, j);

	map[x - 1][y - 1].second > s ? cout << 0 : cout << map[x - 1][y - 1].first;
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