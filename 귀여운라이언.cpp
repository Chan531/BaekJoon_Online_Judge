#include <iostream>
#include <algorithm>
#define N 1010101

using namespace std;

int n, k, ans = N, arr[N], check[N];

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void solution()
{
	int idx = 1;

	for (int i = 1; i <= n; i++)
		if (arr[i] == 1)
			check[idx++] = i;

	for (int i = k; ; i++)
	{
		if (!check[i]) break;
		ans = min(ans, check[i] - check[i - k + 1] + 1);
	}

	if (ans == N)
		cout << -1;

	else
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