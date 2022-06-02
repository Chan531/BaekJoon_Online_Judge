#include <iostream>

using namespace std;

char map[9][9];

void input()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> map[i][j];
}

bool check(int n, char c)
{
	int y = n / 9;
	int x = n % 9;

	for (int i = 0; i < 9; i++)
		if (map[y][i] == c || map[i][x] == c)
			return false;

	y = y / 3 * 3;
	x = x / 3 * 3;

	for (int i = y; i < y + 3; i++)
		for (int j = x; j < x + 3; j++)
			if (map[i][j] == c)
				return false;

	return true;
}

void backtrack(int n)
{
	if (n == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << map[i][j];
			cout << '\n';
		}
		exit(0);
	}

	int y = n / 9;
	int x = n % 9;

	if (map[y][x] != '0')
		backtrack(n + 1);

	else
	{
		for (char c = '1'; c <= '9'; c++)
		{
			if (!check(n, c))
				continue;

			map[y][x] = c;
			backtrack(n + 1);
			map[y][x] = '0';
		}
	}
}

void solution()
{
	backtrack(0);
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