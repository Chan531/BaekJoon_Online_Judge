#include <iostream>
#include <algorithm>
#define N 1500000

using namespace std;

int n, maxval, date[N + 1], val[N + 1], dp[N + 2];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> date[i] >> val[i];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		maxval = max(maxval, dp[i - 1]);
		dp[i] = max(maxval, dp[i]);

		if (i + date[i] > n + 1)
			continue;

		dp[i + date[i]] = max(dp[i] + val[i], dp[i + date[i]]);
	}

	cout << max(dp[n], dp[n + 1]);
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