#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	cin >> n;
	vector<int> arr(n), dp(n, 1001);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			if (i + j < n)
				dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	dp[n - 1] == 1001 ? cout << -1 : cout << dp[n - 1];
	return 0;
}