#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node {
	int y, x;
};

int n, m, map[101][101];
int visited[101][101], dir[4][2] = { {-1, 0},{0,1},{1,0},{0,-1} };

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void setair()             // �ð����� map���� ��� ġ�� ���� -> �̰� ������ ���� : 0�� ������ ġ� �������ֹǷ� ���� ġ� ���۵� ������ֱ� ����
{
	queue<node> q;
	q.push({ 1,1 });
	visited[1][1] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m || visited[ny][nx] == 1)    // ������ ����ų� �̹� �湮�� ���̶�� pass
				continue;

			if (map[ny][nx] == 0)
				q.push({ ny, nx });

			else                    // 0�� ������ ġ���� 0���� �ٲ���
				map[ny][nx] = 0;

			visited[ny][nx] = 1;
		}
	}
}

void solution()
{
	int time = 0, cnt, mcnt = 0;

	while (1)
	{
		cnt = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (map[i][j] == 1)
					cnt++;

		setair();

		if (cnt > 0)     // ġ� �ϳ��� �����Ѵٸ�
		{
			time++;
			mcnt = cnt;
		}

		else
			break;

		memset(visited, 0, sizeof(visited));
	}
	cout << time << '\n' << mcnt;
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