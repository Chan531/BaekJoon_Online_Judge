#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define N 1000
#define K 18
#define INF 1e9
#define p pair<int, int>

using namespace std;

struct node {
	int y, x, cnt;
};

int n, m, k, point[N][N], cost[K][K], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }, dp[K][1 << K];
char map[N][N];
bool visited[N][N];

void input()
{
	cin >> n >> m >> k;

	int idx = 1;
	memset(point, -1, sizeof(point));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'N')
				point[i][j] = idx++;

			else if (map[i][j] == 'U')
				point[i][j] = 0;

			else if (map[i][j] == 'I')
				point[i][j] = k + 1;
		}
	}
}

void bfs(int y, int x, int idx)
{
	queue<node> q;
	q.push({ y, x, 0 });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (point[cury][curx] != -1)
		{
			cost[idx][point[cury][curx]] = cnt;
			cost[point[cury][curx]][idx] = cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int nexty = cury + dir[i][0];
			int nextx = curx + dir[i][1];

			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m || map[nexty][nextx] == '#' || visited[nexty][nextx] == 1)
				continue;

			q.push({ nexty, nextx, cnt + 1 });
			visited[nexty][nextx] = 1;
		}
	}

	memset(visited, 0, sizeof(visited));
}

int tsp(int cur, int check)
{
	if (dp[cur][check] != -1)
		return dp[cur][check];

	int ret = INF;

	if (check == (1 << (k + 1)) - 1)
		return cost[cur][k + 1];

	for (int i = 1; i <= k; i++)
	{
		if (check & (1 << i))
			continue;

		ret = min(ret, tsp(i, check | (1 << i)) + cost[cur][i]);
	}

	return dp[cur][check] = ret;
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (point[i][j] != -1)
				bfs(i, j, point[i][j]);

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1);
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