#include <iostream>

using namespace std;

int r, c, a, b, y, x;
char map[101][101];

void input()
{
	cin >> r >> c >> a >> b;
}

void setMap(char c)
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			map[y + i][x + j] = c;
}

void solution()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i % 2)
			{
				if (j % 2) setMap('X');
				else setMap('.');
			}

			else
			{
				if (j % 2) setMap('.');
				else setMap('X');
			}

			x += b;
		}

		y += a;
		x = 0;
	}

	for (int i = 0; i < r * a; i++)
	{
		for (int j = 0; j < c * b; j++)
			cout << map[i][j];
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

	solve();
	return 0;
}