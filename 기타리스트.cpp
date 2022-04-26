#include <iostream>

using namespace std;

int n, s, m, ans, arr[51], dp[51][1001];           // idx, volume

void input()
{
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	dp[0][s] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] = 1;

				if (j + arr[i] <= m)
					dp[i][j + arr[i]] = 1;
			}
		}
	}

	for (int i = m; i >= -1; i--)
	{
		if (i == -1)
		{
			cout << -1;
			break;
		}

		if (dp[n][i] == 1)
		{
			cout << i;
			break;
		}
	}
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
	cout.tie(NULL);

	solve();
	return 0;
}