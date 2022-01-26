#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector<int> stair(301);
vector<vector<int>> dp(301, vector<int>(2));           // ¿¬¼Ó, °Ç³Ê¶Ü

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		stair[i] = num;
		dp[i][0] = num;
		dp[i][1] = num;
	}
}

void solution()
{
	if (n == 1)
	{
		cout << stair[1];
		return;
	}

	dp[n - 1][0] += stair[n];
	dp[n - 2][1] += stair[n];

	for (int i = n - 3; i >= 1; i--)
	{
		dp[i][0] += dp[i + 1][1];
		dp[i][1] += max(dp[i + 2][0], dp[i + 2][1]);
	}
	cout << max({ dp[1][0], dp[1][1], dp[2][0] });
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	solve();
	return 0;
}