#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int ans;
char map[12][6];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0},{0, -1} };
bool check, visited[12][6];

void input()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];
}

void bfs(int y, int x, char c)
{
	queue<p> q;
	q.push({ y, x });
	visited[y][x] = 1;
	int cnt = 1;

	while (!q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			// 범위에 벗어나거나 알파벳이 같지 않거나 이미 방문했을 경우 pass
			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || map[ny][nx] != c || visited[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
			cnt++;
		}
	}

	if (cnt >= 4)
	{
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				if (visited[i][j])
					map[i][j] = '.';

		check = 1;
	}

	return;
}

void solution()
{
	while (1)
	{
		check = 0;

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (isalpha(map[i][j]) && !visited[i][j])
				{
					visited[i][j] = 1;
					bfs(i, j, map[i][j]);
					memset(visited, 0, sizeof(visited));
				}
			}
		}

		if (check)
			ans++;

		else 
			break;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 11; j >= 0; j--)
			{
				if (isalpha(map[j][i]))
				{
					if (j == 11)
						continue;

					if (map[j + 1][i] == '.')
					{
						map[j + 1][i] = map[j][i];
						map[j][i] = '.';
						j += 2;
					}
				}
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