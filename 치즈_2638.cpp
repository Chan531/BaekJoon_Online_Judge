#include <iostream>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int n, m, map[100][100], dir[4][2] = { {-1 ,0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[100][100];
// map -> -1 (ġ� ���� �� ���� ����) 0 (ġ� ���� �� �ִ� ����) 1 (���� �ʴ� ġ��) 2 (���� ������ ġ��)

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

		// (0, 0)�� ���� ����� ġ� ���� �� �ִ� ����
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

				// ������ ����ų� ġ���� ��� �Ǵ� �̹� �湮�� ������ ��� pass
				if (ny >= n || ny < 0 || nx >= m || nx < 0 || map[ny][nx] || visited[ny][nx])
					continue;

				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}

		// ġ� ���� �� ���� ���� ó��(-1)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!map[i][j] && !visited[i][j])
					map[i][j] = -1;

		// ��� ġ�� Ž�� �� �ּ� 2���� ����(0)��� ������ ��� ġ��� ����(2)
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

		// ���� ġ��� ġ� ���� �� ���� ���⸦ ��� 0���� ����
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