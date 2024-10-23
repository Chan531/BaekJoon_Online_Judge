#include <iostream>
#define N 33444

using namespace std;

int n, mod = 1000000009;
long long dp[N][3];

void input()
{
	cin >> n;
}

void init()
{
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[2][0] = 2;
	dp[2][1] = 2;
	dp[2][2] = 2;
}

void solution()
{
	init();

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = dp[i][0];
		dp[i][2] = dp[i][0];
	}

	cout << dp[n][0];
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