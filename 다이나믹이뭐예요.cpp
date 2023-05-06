#include <iostream>
#include <algorithm>
#define N 1001
#define mod 1000000007

using namespace std;

int n, m, k;
long long dp[N][N];

void input()
{
	cin >> n >> m;
}

void solution()
{
	k = max(n, m);

	for (int i = 1; i <= k; i++)
	{
		dp[1][i] = 1;
		dp[i][1] = 1;
	}

	for (int i = 2; i <= k; i++)
		for (int j = 2; j <= k; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % mod;

	cout << dp[n][m];
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