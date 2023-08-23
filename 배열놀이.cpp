#include <iostream>
#include <cstring>
#define N 1010

using namespace std;

int n, m, r[N], c[N], map[N][N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
}

void solution()
{
	while (m--)
	{
		int r1, c1, r2, c2, v;
		cin >> r1 >> c1 >> r2 >> c2 >> v;

		for (int i = r1; i <= r2; i++)
			r[i] += v * (c2 - c1 + 1);

		for (int i = c1; i <= c2; i++)
			c[i] += v * (r2 - r1 + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;

		for (int j = 1; j <= n; j++)
			ans += map[i][j];

		cout << ans + r[i] << ' ';
	}

	cout << '\n';

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;

		for (int j = 1; j <= n; j++)
			ans += map[j][i];

		cout << ans + c[i] << ' ';
	}

	cout << '\n';

	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}