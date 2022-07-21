#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x, cnt, dis;
};

int n, m, k, ans = -1;
int map[200][200];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int horse[8][2] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2} };
bool visited[200][200][31];
// y, x, k (남은 말 동작 보유 횟수)

void input()
{
	cin >> k >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	queue<node> q;
	q.push({ 0, 0, k, 0 });
	visited[0][0][k] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int dis = q.front().dis;
		q.pop();

		if (y == n - 1 && x == m - 1)
		{
			ans = dis;
			break;
		}

		if (cnt > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int ny = y + horse[i][0];
				int nx = x + horse[i][1];

				// map을 벗어나거나 장애물이거나 남은 말 동작 횟수로 도착한 적이 있는 경우 pass
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx][cnt - 1] || map[ny][nx])
					continue;

				visited[ny][nx][cnt - 1] = 1;
				q.push({ ny, nx, cnt - 1, dis + 1 });
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// map을 벗어나거나 장애물이거나 남은 말 동작 횟수로 도착한 적이 있는 경우 pass
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx][cnt] || map[ny][nx])
				continue;

			visited[ny][nx][cnt] = 1;
			q.push({ ny, nx, cnt, dis + 1 });
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