#include <iostream>
#include <queue>
#include <cstring>
#define p pair<int, int>

using namespace std;

int w, h, cury, curx;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[1002][1002];              // x �Ǵ� y�� 0, w + 1, h + 1�̶�� Ż�⿡ ����
bool visited[1002][1002];

struct node {
	int y, x, t;
};

queue<p> fire;

void input()
{
	cin >> w >> h;

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '@')
			{
				cury = i;
				curx = j;
			}

			if (map[i][j] == '*')
				fire.push({ i, j });
		}
	}
}

// ���� ���� ������ ĭ�� ���� �ʵ��� ���� ��ο� �̸� ���� �ٿ��ִ� �Լ�
void setfire()
{
	int cnt = fire.size();

	while (cnt--)
	{
		int y = fire.front().first;
		int x = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// map ���̰ų� �� �Ǵ� ���̶�� pass
			if (ny == 0 || ny > h || nx == 0 || nx > w || map[ny][nx] == '#' || map[ny][nx] == '*')
				continue;

			fire.push({ ny, nx });
			map[ny][nx] = '*';
		}
	}
}

void solution()
{
	queue<node> q;
	q.push({ cury, curx });
	visited[cury][curx] = 1;
	int ans = 0, curt = -1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int t = q.front().t;
		q.pop();

		if (curt < t)
		{
			setfire();
			curt++;
		}

		// map ���̶�� Ż�� ����
		if (x == 0 || x == w + 1 || y == 0 || y == h + 1)
		{
			ans = t;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			// ������ ĭ�� �� �Ǵ� ���̶��
			if (map[ny][nx] == '#' || map[ny][nx] == '*' || visited[ny][nx])
				continue;

			q.push({ ny, nx, t + 1 });
			visited[ny][nx] = 1;
		}
	}

	// ans�� ���� �ٲ��� �ʾҴٸ� Ż�� x
	ans ? cout << ans << '\n' : cout << "IMPOSSIBLE\n";
}

// ���� ���ɸ� ���� ��� ������ �ʱ�ȭ���ִ� �Լ�
void reset()
{
	while (!fire.empty())
	{
		fire.pop();
	}

	// �� ������ ���ɰ� �������� ������ map�� �ʱ�ȭ�� ���־�� ��
	// ���� �������� w + 1, h + 1�� �ش��ϴ� ĭ�� ���� ���̰ų� ���� ���� �ֱ� ����.
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			map[i][j] = ' ';

	memset(visited, 0, sizeof(visited));
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
		reset();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}