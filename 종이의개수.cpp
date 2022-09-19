#include <iostream>
#define E 2187       // 3^7

using namespace std;

int n, map[E][E], col[3];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

bool check(int y, int x, int l)
{
	int num = map[y][x];

	for (int i = y; i < y + l; i++)
		for (int j = x; j < x + l; j++)
			if (map[i][j] != num)
				return false;

	return true;

}

void dac(int y, int x, int l)
{
	if (check(y, x, l))
	{
		col[map[y][x] + 1]++;
		return;
	}

	for (int i = y; i < y + l; i += l / 3)
		for (int j = x; j < x + l; j += l / 3)
			dac(i, j, l / 3);
}

void solution()
{
	dac(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << col[i] << '\n';
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