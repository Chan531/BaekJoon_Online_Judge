#include <iostream>
#include <algorithm>
#define N 110

using namespace std;

int n, m, map[N][N], ans;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!map[i][j])
				continue;

			int one = 1, two = 1;

			while (j < m && map[i][j])
			{
				if (map[i][j] == 1)
				{
					one++;

					while (j < m && map[i][j] == 1)
						j++;
				}

				else
				{
					two++;

					while (j < m && map[i][j] == 2)
						j++;
				}
			}

			ans += min(one, two);
		}
	}

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