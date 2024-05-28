#include <iostream>
#include <algorithm>
#define N 101010

using namespace std;

int n, k, arr[N * 2], cnt[N], ans;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		while (cnt[arr[i]] == k)
			cnt[arr[idx++]]--;

		cnt[arr[i]]++;
		ans = max(ans, i - idx + 1);
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