#include <iostream>

using namespace std;

int n, m, ans, dir[2][2] = { {1, 0}, {0, 1} };
char map[50][50];
bool check[50][50];

void input()
{
	cin >> n >> m;

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
			if (check[i][j] == 1)
				continue;

			if (map[i][j] == '-')
			{
				int idx = 1;

				while (j + idx < m && map[i][j + idx] == '-')
					check[i][j + idx++] = 1;

				ans++;
			}

			if (map[i][j] == '|')
			{
				int idx = 1;

				while (i + idx < n && map[i + idx][j] == '|')
					check[i + idx++][j] = 1;

				ans++;
			}

			check[i][j] = 1;
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
	cout.tie(NULL);

	solve();
	return 0;
}