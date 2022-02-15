#include <iostream>
#include <vector>

using namespace std;

int n, x, y, cnt, ans = 0;
int map[101][101], dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void color(int x, int y)
{
	for (int i = y; i < y + 10; i++)
	{
		for (int j = x; j < x + 10; j++)
			map[i][j] = 1;
	}
}

void check()
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (!map[i][j])
				continue;

			cnt = 4;

			for (int k = 0; k < 4; k++)
			{
				int ni = i + dir[k][0];
				int nj = j + dir[k][1];

				if (map[ni][nj])
					cnt--;
			}

			ans += cnt;
		}
	}
	cout << ans;
}

void solve()
{
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		color(x, y);
	}
	check();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}