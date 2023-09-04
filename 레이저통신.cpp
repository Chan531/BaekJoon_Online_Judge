#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 110
#define p pair<int, int>
#define y first
#define x second

using namespace std;

struct node {
	int cnt, y, x, dir;
};

struct cmp {
	bool operator()(node a, node b)
	{
		return a.cnt > b.cnt;
	}
};

int n, m, visited[N][N], ans = 1e9;
bool check[N][N][4];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<p> point;
char map[N][N];

void input()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'C')
				point.push_back({ i, j });
		}
	}
}

void init()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 1e9;
}

void solution()
{
	init();
	priority_queue<node, vector<node>, cmp> q;
	q.push({ 0, point[0].y, point[0].x, -1 });

	visited[point[0].y][point[0].x] = 1;

	while (!q.empty())
	{
		node cur = q.top();
		q.pop();

		if (cur.y == point[1].y && cur.x == point[1].x)
		{
			ans = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];
			int ncnt = (i == cur.dir ? cur.cnt : cur.cnt + 1);

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '*')
				continue;

			// 아직 방문하지 않았거나 거울을 덜 써서 방문할 수 있는 경우
			if (visited[ny][nx] == 1e9 || visited[ny][nx] > ncnt)
			{
				q.push({ ncnt, ny, nx, i });
				visited[ny][nx] = ncnt;
				check[ny][nx][i] = 1;
			}

			// 이미 방문한 노드지만 방문한 방향이 다른 경우
			if (visited[ny][nx] == ncnt && !check[ny][nx][i])
			{
				q.push({ ncnt, ny, nx, i });
				visited[ny][nx] = ncnt;
				check[ny][nx][i] = 1;
			}
		}
	}

	cout << ans - 1;
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

	solve();
	return 0;
}