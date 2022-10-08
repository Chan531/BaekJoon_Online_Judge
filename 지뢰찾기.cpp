#include <iostream>

using namespace std;

int n;
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},{0, 1},{1, 1}, {1, 0}, {1, -1},{0, -1} };
int map[1000][1000], ans[1000][1000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char num;
			cin >> num;

			if (num == '.')
				map[i][j] = 0;

			else
				map[i][j] = num - '0';
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j])
			{
				ans[i][j] = 1000;

				for (int k = 0; k < 8; k++)
				{
					int ni = i + dir[k][0];
					int nj = j + dir[k][1];

					if (ni < 0 || ni >= n || nj < 0 || nj >= n)
						continue;

					ans[ni][nj] += map[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans[i][j] >= 1000)
				cout << '*';

			else if (ans[i][j] >= 10)
				cout << 'M';

			else
				cout << ans[i][j];
		}

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