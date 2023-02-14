#include <iostream>
#define mod 1000000007

using namespace std;

int n;
long long dp[51];

void input()
{
	cin >> n;
}

void solution()
{
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % mod;

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
	cout.tie(NULL);

	solve();
	return 0;
}