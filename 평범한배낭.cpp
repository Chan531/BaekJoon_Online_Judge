#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, k, dp[101][100001];
p arr[101];

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if (j >= arr[i].first)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].first] + arr[i].second);
		}
	}

	cout << dp[n][k];
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