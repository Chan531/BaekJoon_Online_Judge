#include <iostream>
#include <algorithm>
#define N 1010101

using namespace std;

int n, k, ans, arr[N];

void input()
{
	cin >> k >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	int s = 0, e = arr[n - 1] + 1;

	while (s <= e)
	{
		int m = (s + e) / 2;
		if (!m) break;
		int idx = lower_bound(arr, arr + n, m) - arr;

		if (n - idx >= k)
		{
			s = m + 1;
			ans = max(ans, m);
			continue;
		}

		long long cnt = 0;
		for (int i = idx; i < n; i++)
			cnt += arr[i] / m;

		if (cnt >= k)
		{
			s = m + 1;
			ans = max(ans, m);
		}

		else
			e = m - 1;
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