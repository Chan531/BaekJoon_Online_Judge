#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x, cnt;
};

int n, m, sy, sx, ey, ex, ans = 1e9;
// s -> �������� ��ǥ, e -> �� ���� ��ǥ
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[50][50];
bool visited[50][50], change = 1;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'D')
			{
				ey = i;
				ex = j;
			}

			if (map[i][j] == 'S')
			{
				sy = i;
				sx = j;
			}
		}
	}
}

// ���� �� ���� ����صδ� �Լ�
void recordwater()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '*')
			{
				for (int k = 0; k < 4; k++)
				{
					int ni = i + dir[k][0];
					int nj = j + dir[k][1];

					// map���� ����ų� ��, ��, ���̸� pass
					if (ni >= n || ni < 0 || nj >= m || nj < 0 || map[ni][nj] == 'D' || map[ni][nj] == 'X' || map[ni][nj] == '*')
						continue;

					// ���� ���� �� ���� O�� ���
					map[ni][nj] = 'O';
				}
			}
		}
	}
}

void setwater()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'O')
				map[i][j] = '*';
}

void solution()
{
	queue<node> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx] = 1;

	while (!q.empty())
	{
		// cnt�� �����ϸ� ���� �� ���� �̸� ���
		if (change)
		{
			recordwater();
			change = 0;
		}

		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (y == ey && x == ex)
		{
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// map���� ����ų� ��, ��, �湮�ߴ� ���̶�� pass
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || map[ny][nx] == '*' || map[ny][nx] == 'X' || map[ny][nx] == 'O' || visited[ny][nx])
				continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx, cnt + 1});
		}

		// q�� ������� �ʰ� ���� ���ʿ� cnt�� �����Ѵٸ� ���� �� ���� ���� ó��
		if (!q.empty() && q.front().cnt > cnt)
		{
			setwater();
			change = 1;
		}
	}

	ans == 1e9 ? cout << "KAKTUS" : cout << ans;
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