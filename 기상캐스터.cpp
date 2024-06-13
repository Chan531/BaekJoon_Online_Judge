#include <iostream>
#include <cstring>

using namespace std;

int n, m, ans[101][101];
char map[101][101];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> map[i][j];
}

void solution()
{
	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j; j--)
		{
			int cnt = 0;

			for (int k = j; k; k--)
			{
				if (map[i][k] == 'c')
				{
					ans[i][j] = cnt;
					break;
				}

				cnt++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
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

	solve();
	return 0;
}