#include <iostream>

using namespace std;

int n, white, blue;
bool map[128][128];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

bool checkcol(int y, int x, int n)
{
	bool col = map[y][x];

	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
			if (map[i][j] != col)
				return false;

	return true;
}

void cut(int y, int x, int n)
{
	if (checkcol(y, x, n))
	{
		if (map[y][x])
			blue++;

		else
			white++;

		return;
	}

	cut(y, x, n / 2);
	cut(y, x + n / 2, n / 2);
	cut(y + n / 2, x, n / 2);
	cut(y + n / 2, x + n / 2, n / 2);
}

void solution()
{
	cut(0, 0, n);

	cout << white << '\n' << blue;
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