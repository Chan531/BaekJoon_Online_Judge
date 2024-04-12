#include <iostream>

using namespace std;

struct node {
	int y, x, cnt;
};

int n, m, k, ans, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[5][5];
bool check[5][5];

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
}

int dfs(int y, int x, int cnt)
{
	if (cnt > k)
		return 0;

	if (y == 0 && x == m - 1 && cnt == k)
		return 1;

	int ret = 0;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || check[ny][nx] || map[ny][nx] == 'T')
			continue;

		check[ny][nx] = 1;
		ret += dfs(ny, nx, cnt + 1);
		check[ny][nx] = 0;
	}

	return ret;
}

void solution()
{
	if (n == 1 && m == 1 && k == 1)
	{
		cout << 1;
		return;
	}

	check[n - 1][0] = 1;
	cout << dfs(n - 1, 0, 1);
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