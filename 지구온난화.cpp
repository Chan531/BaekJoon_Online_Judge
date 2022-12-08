#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char map[10][10], ans[10][10];
int dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0,-1} };

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	int miny = 10, minx = 10, maxy = 0, maxx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '.')
				continue;

			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == '.')
					continue;

				cnt++;
			}

			if (cnt >= 2)
			{
				ans[i][j] = 'X';
				miny = min(miny, i);
				minx = min(minx, j);
				maxy = max(maxy, i);
				maxx = max(maxx, j);
			}
		}
	}

	for (int i = miny; i <= maxy; i++)
	{
		for (int j = minx; j <= maxx; j++)
			ans[i][j] == 'X' ? cout << 'X' : cout << '.';

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
	cout.tie(NULL);

	solve();
	return 0;
}