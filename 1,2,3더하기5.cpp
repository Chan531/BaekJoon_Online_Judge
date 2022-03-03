#include <iostream>
#define mod 1000000009

using namespace std;

int t, n, dp[100001][4];

void setdp()
{
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
}

void solution()
{
	for (int i = 4; i <= n; i++)
	{
		if (dp[i][1] || dp[i][2] || dp[i][3])
			continue;

		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
	}
	cout << ((dp[n][1] % mod + dp[n][2] % mod) % mod + dp[n][3] % mod) % mod << '\n';
}

void solve()
{
	cin >> t;
	setdp();
	while (t--)
	{
		cin >> n;
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