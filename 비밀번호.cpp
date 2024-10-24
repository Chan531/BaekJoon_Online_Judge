#include <iostream>
#include <vector>

using namespace std;

int n, mod = 1234567;
vector<int> v[10];
long long dp[1010][10];

void init()
{
	v[0] = { 7 };
	v[1] = { 2, 4 };
	v[2] = { 1, 3, 5 };
	v[3] = { 2, 6 };
	v[4] = { 1, 5, 7 };
	v[5] = { 2, 4, 6, 8 };
	v[6] = { 3, 5, 9 };
	v[7] = { 0, 4, 8 };
	v[8] = { 5, 7, 9 };
	v[9] = { 6, 8 };

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
				dp[i][j] += dp[i - 1][v[j][k]];

			dp[i][j] %= mod;
		}
	}
}

void input()
{
	cin >> n;
}

void solution()
{
	long long ans = 0;

	for (int i = 0; i < 10; i++)
		ans += dp[n][i];

	cout << ans % mod << '\n';
}

void solve()
{
	init();
	int tc;
	cin >> tc;

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