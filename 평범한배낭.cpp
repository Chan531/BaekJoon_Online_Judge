#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, w, v;
	cin >> n >> k;
	vector<pair<int, int>> item(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		item[i] = { w, v };
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - item[i].first >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].first] + item[i].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k];
	return 0;
}