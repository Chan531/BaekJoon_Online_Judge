#include <iostream>
#include <algorithm>

using namespace std;

int k;
long long n, arr[303030], ans = 1e9;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++) cin >> arr[i];
}

void solution()
{
	long long s = 1, e = 1e9;

	while (s <= e)
	{
		long long m = (s + e) / 2;
		long long cnt = 0;

		for (int i = 0; i < k; i++)
		{
			cnt += arr[i] / m;
			if (arr[i] % m) cnt++;
		}

		if (cnt <= n)
		{
			ans = m;
			e = m - 1;
		}

		else s = m + 1;
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