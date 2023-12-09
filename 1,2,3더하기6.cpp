#include <iostream>
#define N 101010
#define mod 1000000009

using namespace std;

int n;
long long dp[N];

void input()
{
	cin >> n;
}

void solution()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;

	while (n--)
	{
		int m;
		cin >> m;

		if (dp[m])
		{
			cout << dp[m] << '\n';
			continue;
		}

		for (int i = 7; i <= m; i++)
			dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % mod;

		cout << dp[m] << '\n';
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