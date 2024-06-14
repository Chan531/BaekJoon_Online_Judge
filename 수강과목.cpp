#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, k, dp[1010][10010];
p arr[1010];

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= k; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j < arr[i].second) continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].second] + arr[i].first);
		}
	}

	cout << dp[k][n];
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