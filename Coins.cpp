#include <iostream>
#include <cstring>

using namespace std;

int n, m, arr[20], dp[10010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;
}

void solution()
{
	dp[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= m; j++)
			dp[j] += dp[j - arr[i]];

	cout << dp[m] << '\n';
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