#include <iostream>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int n, m, map[100][100], dir[4][2] = { {-1 ,0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[100][100];
// map -> -1 (치즈를 녹일 수 없는 공기) 0 (치즈를 녹일 수 있는 공기) 1 (녹지 않는 치즈) 2 (녹을 예정인 치즈)

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

bool checkmap()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 1)
				return false;

	return true;
}

void solution()
{
	int ans = 0;

	while (1)
	{
		if (checkmap())
			break;

		memset(visited, 0, sizeof(visited));

		// (0, 0)과 접한 공기는 치즈를 녹일 수 있는 공기
		queue<p> q;
		q.push({ 0, 0 });
		visited[0][0] = 1;

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				// 범위를 벗어나거나 치즈일 경우 또는 이미 방문한 공기일 경우 pass
				if (ny >= n || ny < 0 || nx >= m || nx < 0 || map[ny][nx] || visited[ny][nx])
					continue;

				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}

		// 치즈를 녹일 수 없는 공기 처리(-1)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!map[i][j] && !visited[i][j])
					map[i][j] = -1;

		// 모든 치즈 탐색 후 최소 2면이 공기(0)라면 다음에 녹는 치즈로 설정(2)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					int cnt = 0;

					for (int k = 0; k < 4; k++)
					{
						int ni = i + dir[k][0];
						int nj = j + dir[k][1];

						if (map[ni][nj] == 0)
							cnt++;
					}

					if (cnt >= 2)
						map[i][j] = 2;
				}
			}
		}

		// 녹을 치즈와 치즈를 녹일 수 없는 공기를 모두 0으로 변경
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == -1 || map[i][j] == 2)
					map[i][j] = 0;

		ans++;
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