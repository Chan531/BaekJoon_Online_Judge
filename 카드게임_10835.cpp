#include <iostream>
#include <cstring>
#include <algorithm>
#define N 2020

using namespace std;

int n, a[N], b[N], dp[N][N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
}

int dfs(int ai, int bi)
{
	if (ai > n || bi > n) return 0;
	if (dp[ai][bi] != -1) return dp[ai][bi];
	dp[ai][bi] = 0;

	dp[ai][bi] = max(dp[ai][bi], dfs(ai + 1, bi));
	dp[ai][bi] = max(dp[ai][bi], dfs(ai + 1, bi + 1));
	if (a[ai] > b[bi]) dp[ai][bi] = max(dp[ai][bi], b[bi] + dfs(ai, bi + 1));
	return dp[ai][bi];
}

void solution()
{
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 1);
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