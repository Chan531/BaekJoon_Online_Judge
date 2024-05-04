#include <iostream>
#define N 1010
#define mod 1000000009
#define ll long long

using namespace std;

int n, m;
ll dp[N][N];

void init()
{
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;

	for (int i = 4; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1];
			dp[i][j] %= mod;
		}
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}
}

void input()
{
	cin >> n >> m;
}

void solution()
{
	cout << dp[n][m] << '\n';
}

void solve()
{
	int tc;
	cin >> tc;
	init();

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}