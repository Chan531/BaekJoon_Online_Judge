#include <iostream>
#include <cmath>

using namespace std;

int n, k;
double arr[4], dp[101][2];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < 4; i++)
		cin >> arr[i];
}

void solution()
{
	if (k)
	{
		dp[1][0] = arr[2];
		dp[1][1] = arr[3];
	}

	else
	{
		dp[1][0] = arr[0];
		dp[1][1] = arr[1];
	}

	cout << fixed;
	cout.precision(4);

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] * arr[0] + dp[i - 1][1] * arr[2];
		dp[i][1] = dp[i - 1][0] * arr[1] + dp[i - 1][1] * arr[3];
	}

	cout << (int) round(dp[n][0] * 1000) << '\n' << (int) round(dp[n][1] * 1000);
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