#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, l, r, ans = 0;
int map[51][51], visited[51][51], dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };

struct node {
	int y, x;
};

void input()
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
}

void resetvisited()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			visited[i][j] = 0;
}

void solution()
{
	while (1)
	{
		int seq = 1;
		int movecnt = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visited[i][j])   // �̹� ó���� ���̶�� �ѱ�
					continue;

				visited[i][j] = seq;
				queue<node> q;
				q.push({ i, j });
				int val = map[i][j];          // ��ü���� ���ϱ� ����
				int cnt = 1;                  // ������ ���ϱ� ����

				while (!q.empty())
				{
					int y = q.front().y;
					int x = q.front().x;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int ny = y + dir[k][0];
						int nx = x + dir[k][1];

						if (ny <= 0 || ny > n || nx <= 0 || nx > n || visited[ny][nx])    // ���� ����ų� �̹� �湮���� �� �ѱ�
							continue;

						int dif = abs(map[y][x] - map[ny][nx]);

						if (dif >= l && dif <= r)  // �α��̵� ������ �����Ѵٸ�
						{
							visited[ny][nx] = seq;
							q.push({ ny,nx });
							val += map[ny][nx];  // ��ü�� ����
							cnt++;               // ���� ����
							movecnt = 1;         // �α��̵��� �߻������� ���
						}
					}
				}

				if (cnt == 1)    // �α� �̵��� �����ٸ� �׳� �ѱ�
				{
					seq++;
					continue;
				}

				val /= cnt;

				for (int y = 1; y <= n; y++)
				{
					for (int x = 1; x <= n; x++)
					{
						if (visited[y][x] == seq)
							map[y][x] = val;              // �α� ����
					}
				}

				seq++;
			}
		}

		if (!movecnt)
			break;

		ans++;   // movecnt�� 0�� �ƴ϶�� �α��̵��� �־��ٴ� ���̹Ƿ� ans 1 ����
		resetvisited();   // �湮 ��� �ʱ�ȭ
	}

	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
	return 0;
}