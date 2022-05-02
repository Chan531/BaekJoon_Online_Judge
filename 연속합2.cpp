#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100000], dp[100000][2], ans = -1000;
// dp : 0 -> �� ���� x, 1 -> �� ���� o

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	dp[0][0] = arr[0];
	ans = max(ans, arr[0]);

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		// ���� �����ϴ� ��� : ���� idx�� �����ϴ� �� vs �� �� idx�� �����ϴ� ���
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

		ans = max({ ans, dp[i][0], dp[i][1] });
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