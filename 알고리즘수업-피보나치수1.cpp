#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(41);

void solve()
{
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	cout << dp[n] << ' ' << n - 2;
}

int main(void)
{
	solve();
	return 0;
}