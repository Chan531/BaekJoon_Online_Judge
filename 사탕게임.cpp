#include <iostream>
#include <algorithm>
#define N 50

using namespace std;

int n, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }, ans;
char map[N][N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int idx = 0;

			while (i + idx < n && map[i][j] == map[i + idx][j])
				idx++;

			ans = max(ans, idx);

			idx = 0;

			while (j + idx < n && map[i][j] == map[i][j + idx])
				idx++;

			ans = max(ans, idx);
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (ni < 0 || ni >= n || nj < 0 || nj >= n)
					continue;

				swap(map[i][j], map[ni][nj]);
				check();
				swap(map[i][j], map[ni][nj]);
			}
		}
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