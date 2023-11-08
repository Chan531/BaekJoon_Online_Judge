#include <iostream>
#include <algorithm>
#define N 101010

using namespace std;

int n, k, arr[N], sum[N], ans;

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];

	for (int i = 1; i < k; i++)
		sum[n + i] = sum[n + i - 1] + arr[i];

	for (int i = k; i < n + k; i++)
		ans = max(ans, sum[i] - sum[i - k]);

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

	solve();
	return 0;
}