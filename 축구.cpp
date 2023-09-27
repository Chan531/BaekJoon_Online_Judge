#include <iostream>
#define N 19
#define M 10000

using namespace std;

double a, b, dp[N][N][N], p[4], ans;

void input()
{
	cin >> a >> b;
}

void init()
{
	// 둘 다 넣지 못할 확률
	p[0] = (100 - a) * (100 - b) / M;
	dp[1][0][0] = p[0];

	// dp[n][i][j]라 할 때, i팀만 넣을 확률
	p[1] = a * (100 - b) / M;
	dp[1][1][0] = p[1];

	// dp[n][i][j]라 할 때, j팀만 넣을 확률
	p[2] = (100 - a) * b / M;
	dp[1][0][1] = p[2];

	// 둘 다 넣을 확률
	p[3] = a * b / M;
	dp[1][1][1] = p[3];
}

bool check(int i, int j)
{
	if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13 || i == 17)
		return true;

	if (j == 2 || j == 3 || j == 5 || j == 7 || j == 11 || j == 13 || j == 17)
		return true;

	return false;
}

void solution()
{
	cout << fixed;
	cout.precision(18);

	init();

	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k <= i; k++)
			{
				double val = 0;

				// 둘다 넣지 못할 확률
				val += dp[i - 1][j][k] * p[0];

				// j팀만 넣을 확률
				if (j)
					val += dp[i - 1][j - 1][k] * p[1];

				// k팀만 넣을 확률
				if (k)
					val += dp[i - 1][j][k - 1] * p[2];

				// 둘 다 넣을 확률
				if (j && k)
					val += dp[i - 1][j - 1][k - 1] * p[3];

				dp[i][j][k] = val;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (check(i, j))
				ans += dp[18][i][j];

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