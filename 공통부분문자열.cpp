#include <iostream>
#include <algorithm>

using namespace std;

string a, b;
int dp[4001][4001];

void input()
{
	cin >> a >> b;
}

void solution()
{
	int al = a.length(), bl = b.length(), ans = 0;

	for (int i = 1; i <= al; i++)
	{
		for (int j = 1; j <= bl; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans;
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