#include <iostream>
#include <algorithm>
#define N 1010

using namespace std;

int n, m, k, map[N][N];

void input()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			map[i][j] += map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1];
		}
	}
}

void solution()
{
	while (k--)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (map[r2][c2] - map[r1 - 1][c2] - map[r2][c1 - 1] + map[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
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