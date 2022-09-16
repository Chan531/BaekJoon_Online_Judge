#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, q, N, map[64][64];
int icesum, lump;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[64][64];

void input()
{
	cin >> n >> q;

	N = pow(2, n);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
}

void turn(int y, int x, int m)
{
	queue<int> q;
	int cnt = m / 2;

	while (cnt--)
	{
		// ��
		for (int i = x; i < x + m - 1; i++)
			q.push(map[y][i]);

		// ������
		for (int i = y; i < y + m - 1; i++)
			q.push(map[i][x + m - 1]);

		// �Ʒ�
		for (int i = x + m - 1; i > x; i--)
			q.push(map[y + m - 1][i]);

		// ����
		for (int i = y + m - 1; i > y; i--)
			q.push(map[i][x]);

		// �ð� �������� 90�� ������
		// ������
		for (int i = y; i < y + m - 1; i++)
		{
			map[i][x + m - 1] = q.front();
			q.pop();
		}

		// �Ʒ�
		for (int i = x + m - 1; i > x; i--)
		{
			map[y + m - 1][i] = q.front();
			q.pop();
		}

		// ����
		for (int i = y + m - 1; i > y; i--)
		{
			map[i][x] = q.front();
			q.pop();
		}

		// ��
		for (int i = x; i < x + m - 1; i++)
		{
			map[y][i] = q.front();
			q.pop();
		}

		y++;
		x++;
		m -= 2;
	}
}

void icecheck()
{
	queue<p> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// �̹� ���� ĭ�̶��
			if (map[i][j] == 0)
				continue;

			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (ni >= N || ni < 0 || nj >= N || nj < 0)
					continue;

				if (map[ni][nj] > 0)
					cnt++;
			}

			if (cnt < 3)
				q.push({ i, j });
		}
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		map[y][x]--;
		q.pop();
	}
}

void checklump(int y, int x)
{
	queue<p> q;
	q.push({ y, x });
	visited[y][x] = 1;
	int sum = 0;
	
	while (!q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();

		sum++;

		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			if (ny >= N || ny < 0 || nx >= N || nx < 0 || visited[ny][nx] || map[ny][nx] == 0)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	lump = max(lump, sum);
}

void solution()
{
	while (q--)
	{
		int m;
		cin >> m;

		m = pow(2, m);

		for (int i = 0; i < N; i += m)
			for (int j = 0; j < N; j += m)
				turn(i, j, m);

		icecheck();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			icesum += map[i][j];

			// �̹� üũ�߰ų� ������ �ƴ϶��
			if (visited[i][j] || map[i][j] == 0)
				continue;

			checklump(i, j);
		}
	}

	cout << icesum << '\n' << lump;
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