#include <iostream>
#include <queue>
#include <cstring>
#define N 300

using namespace std;

struct node {
	int y, x, cnt;
};

int n, m, map[N][N], val[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
}

void solution()
{
	memset(val, -1, sizeof(val));
	queue<node> q;
	q.push({ 0, 0, map[0][0] });
	val[0][0] = map[0][0];

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (val[cur.y][cur.x] > cur.cnt)
			continue;

		if (cur.y + 1 < n && val[cur.y + 1][cur.x] < cur.cnt + map[cur.y + 1][cur.x])
		{
			q.push({ cur.y + 1, cur.x, cur.cnt + map[cur.y + 1][cur.x] });
			val[cur.y + 1][cur.x] = cur.cnt + map[cur.y + 1][cur.x];
		}

		if (cur.x + 1 < m && val[cur.y][cur.x + 1] < cur.cnt + map[cur.y][cur.x + 1])
		{
			q.push({ cur.y, cur.x + 1, cur.cnt + map[cur.y][cur.x + 1] });
			val[cur.y][cur.x + 1] = cur.cnt + map[cur.y][cur.x + 1];
		}
	}

	cout << val[n - 1][m - 1];
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