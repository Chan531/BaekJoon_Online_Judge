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
		// �� ���� �������� �ʴ� ���
		dp[i][0] = dp[i - 1][0];

		// �ڵθ� ���� �� ������ +1
		if (arr[i] % 2)
			dp[i][0]++;

		for (int j = 1; j <= w; j++)
		{
			// i�ʱ��� j�� �̵����� �� �� �� �ִ� �ִ� ����
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);

			// �ڵθ� ���� �� ������ +1
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