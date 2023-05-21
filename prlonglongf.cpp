#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, ans = 1, dp[21];
string s;
vector<int> val;

void input()
{
	cin >> n >> s;
}

void init()
{
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 20; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
}

void solution()
{
	init();

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;

		while (i < n && s.substr(i, 4) == "long")
		{
			cnt++;
			i += 4;
		}

		if (cnt > 1)
			val.push_back(dp[cnt]);
	}

	for (auto i : val)
		ans *= i;

	cout << ans;
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