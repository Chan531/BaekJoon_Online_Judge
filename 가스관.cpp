#include <iostream>
#define N 30

using namespace std;

int n, m, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }, x, y;
char map[N][N], c;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> map[i][j];
}

void check(int temp, int i, int j)
{
	if (temp == 3)
	{
		y = i;
		x = j;
		c = '2';
	}

	else if (temp == 5)
	{
		y = i;
		x = j;
		c = '|';
	}

	else if (temp == 6)
	{
		y = i;
		x = j;
		c = '1';
	}

	else if (temp == 9)
	{
		y = i;
		x = j;
		c = '3';
	}

	else if (temp == 10)
	{
		y = i;
		x = j;
		c = '-';
	}

	else if (temp == 12)
	{
		y = i;
		x = j;
		c = '4';
	}

	else if (temp == 15)
	{
		y = i;
		x = j;
		c = '+';
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] != '.')
				continue;

			int temp = 0;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (k == 0 && (map[ni][nj] == '|' || map[ni][nj] == '+' || map[ni][nj] == '1' || map[ni][nj] == '4'))
					temp += (1 << k);

				else if (k == 1 && (map[ni][nj] == '-' || map[ni][nj] == '+' || map[ni][nj] == '3' || map[ni][nj] == '4'))
					temp += (1 << k);

				else if (k == 2 && (map[ni][nj] == '|' || map[ni][nj] == '+' || map[ni][nj] == '2' || map[ni][nj] == '3'))
					temp += (1 << k);

				else if (k == 3 && (map[ni][nj] == '-' || map[ni][nj] == '+' || map[ni][nj] == '1' || map[ni][nj] == '2'))
					temp += (1 << k);
			}

			if (!temp)
				continue;

			check(temp, i, j);
		}
	}

	cout << y << ' ' << x << ' ' << c;
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