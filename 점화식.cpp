#include <iostream>

using namespace std;

int n;
long long dp[36];

void input()
{
	cin >> n;
}

void solution()
{
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];

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