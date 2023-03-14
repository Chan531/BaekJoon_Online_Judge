#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x, cnt, key;
};

int n, m, sy, sx, ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[50][50];
bool visited[50][50][1 << 6];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '0')
			{
				sy = i;
				sx = j;
			}
		}
	}
}

void solution()
{
	queue<node> q;
	q.push({ sy,sx,0,0 });
	visited[sy][sx][0] = 1;

	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();

		if (map[cury][curx] == '1')
		{
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			// ������ ����ų� ���̰ų� �湮�� ���� �ִٸ� pass
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#' || visited[ny][nx][key])
				continue;

			// ���� ���� �Ǵ� ���̶��
			if (isalpha(map[ny][nx]))
			{
				// ������
				if (islower(map[ny][nx]))
				{
					q.push({ ny, nx, cnt + 1, key | (1 << (map[ny][nx] - 'a')) });
					visited[ny][nx][key] = 1;
					continue;
				}

				// ���̰� �����ϴ� ���谡 �ִٸ�
				else if (key & (1 << (map[ny][nx] - 'A')))
				{
					q.push({ ny, nx, cnt + 1, key });
					visited[ny][nx][key] = 1;
					continue;
				}

				// ���ٸ� �� ��
				else
					continue;
			}

			q.push({ ny, nx, cnt + 1, key });
			visited[ny][nx][key] = 1;
		}
	}

	ans ? cout << ans : cout << -1;
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