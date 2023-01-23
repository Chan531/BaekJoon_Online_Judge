#include <iostream>

using namespace std;

int h, w, x, y;
int map[601][601], ans[300][300];

void input()
{
	cin >> h >> w >> x >> y;

	for (int i = 0; i < h + x; i++)
		for (int j = 0; j < w + y; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < h; i++)
	{
		if (i < x)
		{
			for (int j = 0; j < w; j++)
				ans[i][j] = map[i][j];
		}

		else
		{
			for (int j = 0; j < w; j++)
			{
				if (j < y)
					ans[i][j] = map[i][j];

				else
					ans[i][j] = map[i][j] - ans[i - x][j - y];
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << ans[i][j] << ' ';

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