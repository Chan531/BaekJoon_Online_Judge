#include <iostream>
#define N 101

using namespace std;

int n, m, ans[N][N];
int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
char map[N][N];

void input()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans[i][j] = 0;

			if (map[i][j] == '*')
			{
				ans[i][j] = -1;
				continue;
			}

			for (int k = 0; k < 8; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (ni < 0 || ni >= n || nj < 0 || nj >= m)
					continue;

				if (map[ni][nj] == '*')
					ans[i][j]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			ans[i][j] == -1 ? cout << '*' : cout << ans[i][j];
		cout << '\n';
	}		
}

void solve()
{
	while (1)
	{
		cin >> n >> m;

		if (!(n * m))
			break;

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