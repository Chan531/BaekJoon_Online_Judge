#include <iostream>
#include <cstring>

using namespace std;

int r, c, n, bomb[201][201], check[201][201], dir[4][2] = { {-1, 0},{0, 1},{1,0},{0,-1} };
char map[201][201];

void input()
{
	cin >> r >> c >> n;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'O')
				bomb[i][j] = 2;
		}
	}
}

void bombcheck()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (check[i][j])
				continue;

			if (bomb[i][j] == 0)
				bomb[i][j] = 1;

			else if (bomb[i][j] == 3)
			{
				bomb[i][j] = 0;
				for (int k = 0; k < 4; k++)
				{
					int ni = i + dir[k][0];
					int nj = j + dir[k][1];

					if (ni > r || ni == 0 || nj > c || nj == 0 || bomb[ni][nj] == 3)
						continue;

					bomb[ni][nj] = 0;
					check[ni][nj] = 1;
				}
			}

			else
				bomb[i][j]++;
		}
	}
}

void solution()
{
	for (int i = 2; i <= n; i++)
	{
		bombcheck();

		for (int i = 1; i <= r; i++)
			memset(check[i], 0, sizeof(check[i]));
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (bomb[i][j] == 0)
				cout << '.';
			else
				cout << 'O';
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