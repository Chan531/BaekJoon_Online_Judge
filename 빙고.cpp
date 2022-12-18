#include <iostream>
#define p pair<int, int>

using namespace std;

int map[5][5], arr[26];
p pos[26];

void input()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
			pos[map[i][j]] = { i, j };
		}
	}

	for (int i = 1; i <= 25; i++)
		cin >> arr[i];
}

void solution()
{
	int cnt = 0;

	for (int i = 1; i <= 25; i++)
	{
		int y = pos[arr[i]].first;
		int x = pos[arr[i]].second;

		map[y][x] = 0;

		for (int j = 0; j < 5; j++)
		{
			if (map[j][x])
				break;

			if (j == 4)
				cnt++;
		}

		for (int j = 0; j < 5; j++)
		{
			if (map[y][j])
				break;

			if (j == 4)
				cnt++;
		}

		if (y == x)
		{
			for (int j = 0; j < 5; j++)
			{
				if (map[j][j])
					break;

				if (j == 4)
					cnt++;
			}
		}

		if (y + x == 4)
		{
			for (int j = 0; j < 5; j++)
			{
				if (map[j][4 - j])
					break;

				if (j == 4)
					cnt++;
			}
		}

		if (cnt >= 3)
		{
			cout << i;
			break;
		}
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