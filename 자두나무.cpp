#include <iostream>
#include <algorithm>

using namespace std;

int t, w, arr[1001], dp[1001][31], ans;

void input()
{
	cin >> t >> w;

	for (int i = 1; i <= t; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= t; i++)
	{
		// 한 번도 움직이지 않는 경우
		dp[i][0] = dp[i - 1][0];

		// 자두를 받을 수 있으면 +1
		if (arr[i] % 2)
			dp[i][0]++;

		for (int j = 1; j <= w; j++)
		{
			// i초까지 j번 이동했을 때 될 수 있는 최댓값 선택
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);

			// 자두를 받을 수 있으면 +1
			if (j % 2 && arr[i] == 2)
				dp[i][j]++;

			if (!(j % 2) && arr[i] == 1)
				dp[i][j]++;
		}
	}

	for (int i = 0; i <= w; i++)
		ans = max(ans, dp[t][i]);

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