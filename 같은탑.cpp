#include <iostream>
#include <algorithm>
#include <cstring>
#define N 55
#define M 505050

using namespace std;

int n, arr[N], dp[N][M];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int dfs(int i, int dif)
{
	if (dp[i][dif] != -1)
		return dp[i][dif];

	if (i == n)
		return dif ? -1e9 : 0;

	int ret = -1e9;

	// 쌓지 않는 경우
	ret = max(ret, dfs(i + 1, dif));

	// 높은 곳에 쌓는 경우
	ret = max(ret, dfs(i + 1, dif + arr[i]) + arr[i]);

	// 낮은 곳에 쌓는 경우

	// 높은 탑과 낮은 탑이 뒤바뀌는 경우
	if (dif < arr[i])
		ret = max(ret, dfs(i + 1, arr[i] - dif) + arr[i] - dif);

	// 유지되는 경우
	else
		ret = max(ret, dfs(i + 1, dif - arr[i]));

	return dp[i][dif] = ret;
}

void solution()
{
	memset(dp, -1, sizeof(dp));
	int ans = dfs(0, 0);
	cout << (ans ? ans : -1);
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