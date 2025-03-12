#include <iostream>
#include <algorithm>
#define N 404

using namespace std;

int v, e, ans = 1e9, dis[N][N];

void input()
{
	cin >> v >> e;

	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dis[a][b] = c;
	}
}

void init()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j) dis[i][j] = 0;
			else if (dis[i][j]) continue;
			dis[i][j] = 1e9;
		}
	}
}

void solution()
{
	init();

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			for (int k = 1; k <= v; k++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j) continue;
			ans = min(ans, dis[i][j] + dis[j][i]);
		}
	}

	if (ans == 1e9) ans = -1;
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