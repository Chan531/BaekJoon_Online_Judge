#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, w = 0, b = 0, cnt;
vector<vector<char>> map(100, vector<char>(100));
vector<vector<int>> visited(100, vector<int>(100)), dir = { {-1, 0}, {0, 1}, {1, 0},{0,-1} };

void input()
{
	string line;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> line;
		for (int j = 0; j < n; j++)
			map[i][j] = line[j];
	}
}

int bfs(int j, int i, char col)
{
	if (!visited[i][j])
	{
		cnt = 0;
		queue<pair<int, int>> q;
		visited[i][j] = 1;
		q.push({ i, j });
		while (!q.empty())
		{
			int x = q.front().second;
			int y = q.front().first;
			q.pop();

			cnt++;

			for (int k = 0; k < 4; k++)
			{
				int nx = x + dir[k][1];
				int ny = y + dir[k][0];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[ny][nx] && map[ny][nx] == col)
				{
					visited[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
		return cnt * cnt;
	}
	return 0;
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			map[i][j] == 'W' ? w += bfs(j, i, 'W') : b += bfs(j, i, 'B');
	}
	cout << w << ' ' << b;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	solve();
	return 0;
}