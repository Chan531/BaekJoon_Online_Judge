#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[2][202020], dp[2][202020];

void input()
{
	cin >> n;

	for (int i = 0; i < 2; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> arr[i][j];
}

void solution()
{
	dp[0][1] = max(arr[0][1], arr[0][1] + arr[1][1]);
	dp[1][1] = arr[0][1] + arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = arr[0][i] + dp[0][i - 1];
		dp[1][i] = arr[1][i] + dp[1][i - 1];

		long long top = max({ dp[0][i], dp[0][i] + arr[1][i], dp[1][i] + arr[0][i] });
		long long bottom = max({ dp[1][i], dp[1][i] + arr[0][i], dp[0][i] + arr[1][i] });

		dp[0][i] = top;
		dp[1][i] = bottom;
	}

	cout << dp[1][n];
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