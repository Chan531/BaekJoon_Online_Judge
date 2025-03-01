#include <iostream>

using namespace std;

int r, c, ans, dir[3][2] = { {-1, 1}, {0, 1}, {1, 1} };
char map[10101][505];
bool visited[10101][505];

void input()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];
}

bool dfs(int y, int x) {
	if (x == c - 1) return 1;

	for (int j = 0; j < 3; j++) {
		int ny = y + dir[j][0];
		int nx = x + dir[j][1];

		if (ny < 0 || ny >= r || visited[ny][nx] || map[ny][nx] == 'x') continue;

		visited[ny][nx] = 1;
		if (!dfs(ny, nx)) continue;
		return 1;
	}

	return 0;
}

void solution()
{
	for (int i = 0; i < r; i++)
		if (dfs(i, 0)) ans++;

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