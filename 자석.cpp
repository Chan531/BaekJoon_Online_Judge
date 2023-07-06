#include <iostream>
#include <algorithm>
#include <cmath>
#define N 505050
#define ll long long
#define p pair<ll, int>

using namespace std;

int n;
ll k, ans;
p arr[N];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i].first, arr[i].second = i;
}

void solution()
{
	ll m = arr[0].first;
	int idx = 0;
	ans = abs(arr[0].first - arr[1].first) - k;

	for (int i = 1; i < n; i++)
	{
		ans = max(ans, abs(m - arr[i].first) - ((i - idx) * k));

		if (m - ((i - idx) * k) < arr[i].first)
		{
			m = arr[i].first;
			idx = arr[i].second;
		}
	}

	m = arr[n - 1].first;
	idx = n - 1;

	for (int i = n - 2; i >= 0; i--)
	{
		ans = max(ans, abs(m - arr[i].first) - (idx - i) * k);

		if (m - (idx - i) * k < arr[i].first)
		{
			m = arr[i].first;
			idx = arr[i].second;
		}
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