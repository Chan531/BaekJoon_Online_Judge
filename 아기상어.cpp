#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, map[21][21], visited[21][21], cy, cx, csize = 2, stack = 0;            
// cy, cx -> �Ʊ� ����� ���� ��ǥ, csize -> �Ʊ� ����� ���� ũ��, stack -> ũ�Ⱑ Ŀ���� ���� ���� ����� ��
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

struct node {
	int y, x, dis;
};

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 9)        // �Ʊ� ����� ���� ��ġ ���
			{
				cy = i;
				cx = j;
				map[i][j] = 0;
			}
		}
	}
}

/*bool checkmap()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] != 0 && map[i][j] < csize)   // ���� �Ʊ� �� ���ƴٴ� �� ���� -> ������ ������� �������� ���� ���� �����Ƿ� �ļ� �۾� �ʿ�
				return false;

	return true;
}*/

void solution()
{
	int cnt = 0;     // ��ü �ð�

	while (1)
	{
		/*if (checkmap())
			break;*/

		vector<p> ablefish;       // ���� �� �ִ� ����⸦ ��� �迭
		int dislimit = 1e9;
		queue<node> q;
		q.push({ cy, cx, 0 });
		visited[cy][cx] = 1;

		while (!q.empty())
		{
			int cury = q.front().y;
			int curx = q.front().x;
			int curdis = q.front().dis;
			q.pop();

			if (curdis >= dislimit)          // ���� �� �ִ� ����Ⱑ �ְ� �� �Ÿ����� ��ٸ� pass
				continue;

			for (int i = 0; i < 4; i++)
			{
				int ny = cury + dir[i][0];
				int nx = curx + dir[i][1];

				if (ny > n || ny == 0 || nx > n || nx == 0 || visited[ny][nx] || map[ny][nx] > csize)
					continue;

				visited[ny][nx] = 1;

				if (map[ny][nx] == 0 || map[ny][nx] == csize)
				{
					q.push({ ny, nx, curdis + 1 });
					continue;
				}

				// ���� �� �ִ� �������?
				ablefish.push_back({ ny, nx });
				dislimit = curdis + 1;
			}
		}

		if (ablefish.size())
		{
			sort(ablefish.begin(), ablefish.end());
			cnt += dislimit;
			stack++;

			// �Ʊ� ��� ũ�� �÷��ֱ�
			if (stack == csize)
			{
				csize++;
				stack = 0;
			}

			// �Ʊ� ��� ��ġ �Ű��ֱ�
			cy = ablefish[0].first;
			cx = ablefish[0].second;
			map[cy][cx] = 0;

			ablefish.clear();
		}

		else               // ���� �� �ִ� ����Ⱑ �����Ƿ�
			break;

		memset(visited, 0, sizeof(visited));
	}
	cout << cnt;
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