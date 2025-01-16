#include <iostream>

using namespace std;

int n, k, mod = 1000000007;
long long dp[10101];

void input()
{
	cin >> n >> k;
}

void solution()
{
	for (int i = 1; i <= k; i++)
		dp[i] = 1;

	dp[k]++;

	for (int i = k + 1; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - k]) % mod;
	cout << dp[n];
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