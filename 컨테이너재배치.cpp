#include <iostream>
#include <algorithm>
#include <numeric>
#define N 1000010
#define ll long long

using namespace std;

int n;
ll arr[N], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);
	ll sum = accumulate(arr, arr + n, 0L);
	int minv = n - sum % n;

	for (int i = 0; i < minv; i++)
	{
		if (sum / n <= arr[i])
			continue;

		ans += sum / n - arr[i];
	}

	for (int i = minv; i < n; i++)
	{
		if (sum / n + 1 <= arr[i])
			continue;

		ans += sum / n + 1 - arr[i];
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