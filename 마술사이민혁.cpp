#include <iostream>

using namespace std;

int n, m, y, x;
char map[111][111];

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> map[i][j];
	cin >> y >> x;
}

void solution()
{
	// 오른쪽 대칭
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			map[i][2 * m - j + 1] = map[i][j];

	// 아래 대칭
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 2 * m; j++)
			map[2 * n - i + 1][j] = map[i][j];

	if (map[y][x] == '#') map[y][x] = '.';
	else map[y][x] = '#';

	for (int i = 1; i <= 2 * n; i++)
	{
		for (int j = 1; j <= 2 * m; j++)
			cout << map[i][j];
		cout << '\n';
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

	solve();
	return 0;
}