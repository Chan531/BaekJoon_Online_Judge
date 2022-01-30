#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> dp(n + 1);
	dp[1] = { 3, 1 };
	for (int i = 2; i <= n; i++)
		dp[i] = { (2 * dp[i - 1].first + dp[i - 1].second) % 9901, dp[i - 1].first % 9901 };
	cout << dp[n].first;
	return 0;
}