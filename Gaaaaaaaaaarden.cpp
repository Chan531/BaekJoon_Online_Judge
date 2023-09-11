#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define N 55
#define p pair<int, int>
#define y first
#define x second

using namespace std;

struct node {
	int y, x, type, cnt;
};

int n, m, g, r, map[N][N], check[11], ans;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<p> v, gq, rq;
int visited[N][N][2];
queue<node> q;

void input()
{
	cin >> n >> m >> g >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				v.push_back({ i, j });
		}
	}
}

void bfs()
{
	int ret = 0;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (visited[cur.y][cur.x][0] == visited[cur.y][cur.x][1] && visited[cur.y][cur.x][cur.type])
			continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dir[i][0];
			int nx = cur.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 0 || visited[ny][nx][cur.type])
				continue;

			if (!visited[ny][nx][(cur.type + 1) % 2] || visited[ny][nx][(cur.type + 1) % 2] == cur.cnt + 1)
			{
				visited[ny][nx][cur.type] = cur.cnt + 1;
				q.push({ ny, nx, cur.type, cur.cnt + 1 });
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j][0] == visited[i][j][1] && visited[i][j][0])
				ret++;

	ans = max(ans, ret);
}

void sprinkle()
{
	// 초록색 배양액 지점 삽입
	for (int i = 0; i < gq.size(); i++)
	{
		visited[gq[i].y][gq[i].x][0] = 1;
		q.push({ gq[i].y, gq[i].x, 0, 1 });
	}

	// 빨강색 배양액 지점 삽입
	for (int i = 0; i < rq.size(); i++)
	{
		visited[rq[i].y][rq[i].x][1] = 1;
		q.push({ rq[i].y, rq[i].x, 1, 1 });
	}

	bfs();
	memset(visited, 0, sizeof(visited));
}

void r_backtrack(int idx, int cnt)
{
	if (cnt == r)
	{
		sprinkle();
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (check[i])
			continue;

		check[i] = 2;
		rq.push_back(v[i]);
		r_backtrack(i + 1, cnt + 1);
		check[i] = 0;
		rq.pop_back();
	}
}

void g_backtrack(int idx, int cnt)
{
	if (cnt == g)
	{
		r_backtrack(0, 0);
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (check[i])
			continue;

		check[i] = 1;
		gq.push_back(v[i]);
		g_backtrack(i + 1, cnt + 1);
		check[i] = 0;
		gq.pop_back();
	}
}

void solution()
{
	g_backtrack(0, 0);
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

	solve();
	return 0;
}