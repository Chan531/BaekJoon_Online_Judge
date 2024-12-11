#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define p pair<int, int>

using namespace std;

struct node {
	int val, y, x;
};

int n, m, ans, map[101][77], dir[8][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1} };
bool visited[101][77];
vector<node> v;

bool cmp(node a, node b)
{
	return a.val > b.val;
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j]) v.push_back({ map[i][j], i, j });
		}
	}
}

void bfs(int y, int x)
{
	queue<p> q;
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !map[ny][nx] || map[ny][nx] > map[cury][curx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}
}

void solution()
{
	sort(v.begin(), v.end(), cmp);

	for (auto i : v)
	{
		if (visited[i.y][i.x]) continue;
		bfs(i.y, i.x);
		ans++;
	}

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