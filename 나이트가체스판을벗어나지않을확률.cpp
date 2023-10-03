#include <iostream>
#define N 55

using namespace std;

int n, x, y, k;
int dir[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
double dp[N][N][N], ans;

void input()
{
	cin >> n >> x >> y >> k;
}

void solution()
{
	cout << fixed;
	cout.precision(12);

	dp[0][x][y] = 1;

	for (int i = 0; i < k; i++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				if (dp[i][a][b] == 0)
					continue;

				for (int j = 0; j < 8; j++)
				{
					int na = a + dir[j][0];
					int nb = b + dir[j][1];

					if (na <= 0 || na > n || nb <= 0 || nb > n)
						continue;

					dp[i + 1][na][nb] += dp[i][a][b] * 0.125;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += dp[k][i][j];

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