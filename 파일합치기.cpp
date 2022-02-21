#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, num;
int page[501], sum[501], dp[501][501];

void solve()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> page[i];
			sum[i] = sum[i - 1] + page[i];
		}

		for (int i = 1; i <= n; i++)                  // 더하는 범위의 길이
		{
			for (int j = 1; j <= n - i; j++)          // 더할 범위의 시작점
			{
				dp[j][i + j] = 1e9;
				for (int k = j; k < i + j; k++)       // 구간 나누기
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
			}
		}
		cout << dp[1][n] << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}