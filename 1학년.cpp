#include <iostream>
#include <vector>

using namespace std;

int n, num[101];
long long dp[101][21];

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
}

void solution()
{
	dp[1][num[1]] = 1;

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j])
			{
				if (j + num[i] <= 20)
					dp[i][j + num[i]] += dp[i - 1][j];

				if (j - num[i] >= 0)
					dp[i][j - num[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 1][num[n]];
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