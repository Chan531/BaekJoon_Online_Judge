#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[2][100000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> dp[0][i];

	for (int i = 0; i < n; i++)
		cin >> dp[1][i];
}

void solution()
{
	dp[0][1] += dp[1][0];
	dp[1][1] += dp[0][0];

	for (int i = 2; i < n; i++)
	{
		dp[0][i] += max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] += max(dp[0][i - 1], dp[0][i - 2]);
	}

	cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}