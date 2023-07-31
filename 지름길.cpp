#include <iostream>
#include <vector>
#include <algorithm>
#define N 10010
#define p pair<int, int>

using namespace std;

int n, d, dp[N];
vector<p> sc[N];

void input()
{
	cin >> n >> d;

	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		sc[b].push_back({ a, c });
	}
}

void solution()
{
	for (int i = 1; i <= d; i++)
	{
		dp[i] = dp[i - 1] + 1;

		for (int j = 0; j < sc[i].size(); j++)
			dp[i] = min(dp[i], dp[sc[i][j].first] + sc[i][j].second);
	}

	cout << dp[d];
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