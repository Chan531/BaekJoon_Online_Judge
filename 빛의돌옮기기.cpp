#include <iostream>
#include <algorithm>
#define p pair<int, int>
#define N 200001

using namespace std;

int n, k;
p arr[N];
long long dp[2][N];

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].first;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].second;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = arr[i].first;
		dp[0][i] += min(dp[0][i - 1], dp[1][i - 1] + k);

		dp[1][i] = arr[i].second;
		dp[1][i] += min(dp[0][i - 1] + k, dp[1][i - 1]);
	}

	cout << min(dp[0][n], dp[1][n]);
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