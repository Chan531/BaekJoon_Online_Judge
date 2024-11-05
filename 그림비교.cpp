#include <iostream>

using namespace std;

int n, ans[2], dif = 36;
char map[55][5][7];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 7; k++)
				cin >> map[i][j][k];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int cnt = 0;

			for (int l = 0; l < 5; l++)
			{
				for (int k = 0; k < 7; k++)
				{
					if (map[i][l][k] != map[j][l][k])
						cnt++;
				}
			}

			if (dif > cnt)
			{
				dif = cnt;
				ans[0] = i;
				ans[1] = j;
			}
		}
	}

	cout << ans[0] << ' ' << ans[1];
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