#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, map[1010][1010], sy, sx, ey, ex;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
			{
				sy = i;
				sx = j;
			}

			else if (map[i][j] == 5)
			{
				ey = i;
				ex = j;
			}
		}
	}
}

void solution()
{
	int cnt = 0;

	if (sy > ey) swap(sy, ey);

	if (sx > ex) swap(sx, ex);

	for (int i = sy; i <= ey; i++)
		for (int j = sx; j <= ex; j++)
			if (map[i][j] == 1) cnt++;

	int r = pow(sy - ey, 2) + pow(sx - ex, 2);

	cout << (cnt >= 3 && r >= 25) ? 1 : 0;
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