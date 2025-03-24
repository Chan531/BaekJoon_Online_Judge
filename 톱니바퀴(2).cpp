#include <iostream>
#include <cstring>

using namespace std;

int t, k, check[1010], ans;
char map[1010][8];

void input()
{
	cin >> t;
	for (int i = 1; i <= t; i++)
		for (int j = 0; j < 8; j++)
			cin >> map[i][j];
	cin >> k;
}

void turnLeft(int a)
{
	int temp[8];
	for (int i = 0; i < 8; i++) temp[i] = map[a][i];
	for (int i = 0; i < 8; i++) map[a][i] = temp[(i + 1) % 8];
}

void turnRight(int a)
{
	int temp[8];
	for (int i = 0; i < 8; i++) temp[i] = map[a][i];
	for (int i = 0; i < 8; i++) map[a][(i + 1) % 8] = temp[i];
}

void solution()
{
	while (k--)
	{
		int a, b;
		memset(check, 0, sizeof(check));

		cin >> a >> b;

		if (b == -1)
		{
			check[a] = -1;

			for (int i = a - 1; i; i--)
			{
				if (map[i + 1][6] == map[i][2]) break;
				if (check[i + 1] == -1) check[i] = 1;
				else check[i] = -1;
			}

			for (int i = a + 1; i <= t; i++)
			{
				if (map[i][6] == map[i - 1][2]) break;
				if (check[i - 1] == -1) check[i] = 1;
				else check[i] = -1;
			}
		}

		else
		{
			check[a] = 1;

			for (int i = a - 1; i; i--)
			{
				if (map[i + 1][6] == map[i][2]) break;
				if (check[i + 1] == -1) check[i] = 1;
				else check[i] = -1;
			}

			for (int i = a + 1; i <= t; i++)
			{
				if (map[i][6] == map[i - 1][2]) break;
				if (check[i - 1] == -1) check[i] = 1;
				else check[i] = -1;
			}
		}

		for (int i = 1; i <= t; i++)
		{
			if (check[i] == 1) turnRight(i);
			else if (check[i] == -1) turnLeft(i);
		}
	}

	for (int i = 1; i <= t; i++)
		if (map[i][0] == '1')
			ans++;

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

	solve();
	return 0;
}