#include <iostream>
#include <algorithm>
#define N 202020

using namespace std;

int n, arr[N], ans, maxv;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = n; i; i--)
	{
		ans = max(ans, maxv - arr[i]);
		maxv = max(arr[i], maxv);
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

	solve();
	return 0;
}