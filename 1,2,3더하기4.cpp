#include <iostream>
#include <numeric>

using namespace std;

int n, dp[10010][3];

void input()
{
	cin >> n;
}

void solution()
{
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 2;
	dp[3][2] = 1;

	if (dp[n][0])
	{
		cout << accumulate(dp[n], dp[n] + 3, 0) << '\n';
		return;
	}

	for (int i = 4; i <= n; i++)
	{
		if (dp[i][0])
			continue;

		dp[i][0] = accumulate(dp[i - 1], dp[i - 1] + 3, 0);
		dp[i][1] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][2] = dp[i - 3][2];
	}

	cout << accumulate(dp[n], dp[n] + 3, 0) << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}