#include <iostream>
#include <algorithm>
#define N 202020

using namespace std;

int n, arr[N], dp[N];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	int a = arr[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1], arr[i] - a);
		a = min(a, arr[i]);
	}

	for (int i = 0; i < n; i++) cout << dp[i] << ' ';
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