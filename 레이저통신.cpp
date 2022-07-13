#include <iostream>
#include <queue>

using namespace std;

struct node {
	int turn, dir, y, x;
};

int n, m, check[100][100], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[100][100];
node start;

struct cmp
{
	bool operator()(node a, node b)
	{
		return a.turn > b.turn;
	}
};

void input()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'C')
			{
				start.y = i;
				start.x = j;
			}
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			check[i][j] = 1e9;

	priority_queue<node, vector<node>, cmp> pq;

	start.turn = 0;
	start.dir = -1;

	pq.push(start);

	while (!pq.empty())
	{
		int cury = pq.top().y;
		int curx = pq.top().x;
		int curdir = pq.top().dir;
		int turncnt = pq.top().turn;
		pq.pop();

		if (check[cury][curx] < turncnt)
			continue;

		check[cury][curx] = turncnt;

		if (map[cury][curx] == 'C')
		{
			if (cury == start.y && curx == start.x)
			{

			}

			else
			{
				cout << check[cury][curx];
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			// 범위에 벗어나거나 벽일 경우
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '*')
				continue;

			// 전 방향과 같거나 시작 상태일 경우
			if (curdir == i || curdir == -1)
				pq.push({ turncnt, i, ny, nx });

			// 거울을 사용해야 하는 경우
			else
				pq.push({ turncnt + 1, i, ny, nx });
		}
	}
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