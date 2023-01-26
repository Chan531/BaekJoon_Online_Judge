#include <iostream>
#include <cstring>
#include <queue>
#define N 1000

using namespace std;

struct node {
	int y, x, cnt, des;
};

int n, m, ans = -1, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[N][N];
bool visited[N][N][2];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	memset(visited, 0, sizeof(visited));

	queue<node> q;
	q.push({ 0, 0, 1, 0 });
	visited[0][0][0] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int des = q.front().des;
		q.pop();

		if (y == n - 1 && x == m - 1)
		{
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// map 벗어나면 pass
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;

			// 길이고 현재 남은 des로 아직 방문하지 않았다면
			if (map[ny][nx] == '0' && !visited[ny][nx][des])
			{
				visited[ny][nx][des] = 1;
				q.push({ ny, nx, cnt + 1, des });
			}

			// 벽이고 아직 부술 수 있다면 
			if (map[ny][nx] == '1' && des != 1)
			{
				visited[ny][nx][des + 1] = 1;
				q.push({ ny, nx, cnt + 1, des + 1 });
			}
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