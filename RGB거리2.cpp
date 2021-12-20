#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, ans = 1000001;
	vector<int> col(3001), dp(3001);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> num;
			col[i * 3 + j] = num;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		copy(col.begin(), col.end(), dp.begin());
		for (int j = 1; j <= 3; j++)
		{
			if (i == j)
				continue;
			dp[j] = 1000000;
		}
		for (int j = 1; j < n; j++)
		{
			dp[j * 3 + 1] += min(dp[(j - 1) * 3 + 2], dp[j * 3]);
			dp[j * 3 + 2] += min(dp[(j - 1) * 3 + 1], dp[j * 3]);
			dp[(j + 1) * 3] += min(dp[(j - 1) * 3 + 1], dp[(j - 1) * 3 + 2]);
		}
		for (int j = 1; j <= 3; j++)
		{
			if (i == j)
				continue;
			ans = min(ans, dp[(n - 1) * 3 + j]);
		}
	}
	cout << ans;
	return 0;
}