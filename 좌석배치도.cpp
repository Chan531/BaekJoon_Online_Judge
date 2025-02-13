#include <iostream>

using namespace std;

int n;
char map[10][20];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			map[i][j] = '.';

	while (n--)
	{
		char c;
		int a;
		cin >> c >> a;

		map[c - 'A'][a - 1] = 'o';
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
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