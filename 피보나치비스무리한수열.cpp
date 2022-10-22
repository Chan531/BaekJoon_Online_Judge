#include <iostream>

using namespace std;

int n;
long long dp[117];

void input()
{
	cin >> n;
}

void solution()
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 3] + dp[i - 1];

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