#include <iostream>
#include <vector>
#define mod 1000000009;

using namespace std;

int n, m;
long long dp[1000001];

void solution()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (n--)
	{
		cin >> m;

		if (dp[m])
		{
			cout << dp[m] << '\n';
			continue;
		}

		for (int i = 4; i <= m; i++)
		{
			if (!dp[i])
				dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
		}

		cout << dp[m] << '\n';
	}
}

void solve()
{
	cin >> n;
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