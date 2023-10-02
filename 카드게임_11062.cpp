#include <iostream>
#include <cstring>
#include <algorithm>
#define N 1010

using namespace std;

int n, arr[N], dp[N][N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

int dfs(int l, int r, int idx)
{
	if (l == r)
	{
		if (idx % 2)
			return 0;

		return dp[l][r] = arr[l];
	}

	if (dp[l][r])
		return dp[l][r];

	if (idx % 2)
		return dp[l][r] = min(dfs(l + 1, r, idx + 1), dfs(l, r - 1, idx + 1));

	else
		return dp[l][r] = max(dfs(l + 1, r, idx + 1) + arr[l], dfs(l, r - 1, idx + 1) + arr[r]);
}

void solution()
{
	dfs(1, n, 0);
	cout << dp[1][n] << '\n';
	memset(dp, 0, sizeof(dp));
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}