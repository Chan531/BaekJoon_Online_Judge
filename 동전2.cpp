#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, num;
vector<int> coin, dp(10001, 10001);

void input()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		coin.push_back(num);
	}
}

void solution()
{
	dp[0] = 0;
	for (auto i : coin)
	{
		if (i > k)
			continue;
		for (int j = i; j <= k; j++)
			dp[j] = min(dp[j], dp[j - i] + 1);
	}
	dp[k] != 10001 ? cout << dp[k] : cout << -1;
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