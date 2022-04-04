#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m, a[1000], b[1000], arr[500501], brr[500501];
long long ans = 0;

void input()
{
	cin >> t >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
}

void solution()
{
	int acnt = 0, bcnt = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = a[i];
		arr[acnt++] = sum;
		for (int j = i + 1; j < n; j++)
		{
			sum += a[j];
			arr[acnt++] = sum;
		}
	}
	sort(arr, arr + acnt);

	for (int i = 0; i < m; i++)
	{
		int sum = b[i];
		brr[bcnt++] = sum;
		for (int j = i + 1; j < m; j++)
		{
			sum += b[j];
			brr[bcnt++] = sum;
		}
	}
	sort(brr, brr + bcnt);

	for (int i = 0; i < acnt; i++)
	{
		int maxidx = upper_bound(brr, brr + bcnt, t - arr[i]) - brr;
		int minidx = lower_bound(brr, brr + bcnt, t - arr[i]) - brr;
		ans += maxidx - minidx;
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
	cout.tie(NULL);

	solve();
	return 0;
}