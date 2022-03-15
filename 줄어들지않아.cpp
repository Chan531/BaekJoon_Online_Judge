#include <iostream>

using namespace std;

int t, n;
long long sum, dp[65][10];

void setdp()
{
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
}

void input()
{
	cin >> n;
}

void solution()
{
	sum = 0;

	if (dp[n][9])
	{
		for (int i = 0; i < 10; i++)
			sum += dp[n][i];
		cout << sum << '\n';
	}

	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (dp[i][0])
				continue;

			dp[i][0] = dp[i - 1][0];

			for (int j = 1; j < 10; j++)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}

		for (int i = 0; i < 10; i++)
			sum += dp[n][i];
		cout << sum << '\n';
	}
}

void solve()
{
	cin >> t;
	setdp();
	while (t--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}