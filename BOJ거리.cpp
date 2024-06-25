#include <iostream>
#include <algorithm>
#define N 1010

using namespace std;

int n, arr[N], dp[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;

		if (c == 'B')
			arr[i] = 1;

		else if (c == 'O')
			arr[i] = 2;

		else
			arr[i] = 3;
	}
}

void solution()
{
	for (int i = 2; i <= n; i++)
		dp[i] = 1e9;

	dp[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (dp[j] == -1 || (arr[i] - 1) % 3 != (arr[j] % 3)) continue;
			dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
		}
	}

	if (dp[n] == 1e9)
		dp[n] = -1;

	cout << dp[n];
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