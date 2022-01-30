#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<vector<int>> map(100, vector<int>(100));
vector<vector<long long>> dp(100, vector<long long>(100));

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			map[i][j] = num;
		}
	}
}

void solution()
{
	dp[0][0] = 1;
	map[n - 1][n - 1] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j])
			{
				if (i + map[i][j] < n)
					dp[i + map[i][j]][j] += dp[i][j];
				if (j + map[i][j] < n)
					dp[i][j + map[i][j]] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1];
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