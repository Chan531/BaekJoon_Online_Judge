#include <iostream>

using namespace std;

int n;
long long dp[30];

void input()
{
	cin >> n;
}

void solution()
{
	dp[2] = 1;

	for (int i = 4; i <= n; i += 2)
		dp[i] = dp[i - 2] * (i - 1);

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