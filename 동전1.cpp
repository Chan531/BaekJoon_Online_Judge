#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k, num;
	cin >> n >> k;
	vector<int> coin, dp(k + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		coin.push_back(num);
	}
	sort(coin.begin(), coin.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k];
	return 0;
}