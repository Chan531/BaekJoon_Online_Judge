#include <iostream>
#define N 101010
#define p pair<long long, long long>
#define mod 1000000009

using namespace std;

int n;
p dp[N];

void init()
{
	dp[1] = { 1, 0 };
	dp[2] = { 1, 1 };
	dp[3] = { 2, 2 };
}

void input()
{
	cin >> n;
}

void solution()
{
	if (dp[n].first)
	{
		cout << dp[n].first << ' ' << dp[n].second << '\n';
		return;
	}

	for (int i = 4; i <= n; i++)
	{
		if (dp[i].first)
			continue;

		dp[i].first = (dp[i - 1].second + dp[i - 2].second + dp[i - 3].second) % mod;
		dp[i].second = (dp[i - 1].first + dp[i - 2].first + dp[i - 3].first) % mod;
	}

	cout << dp[n].first << ' ' << dp[n].second << '\n';
}

void solve()
{
	init();
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