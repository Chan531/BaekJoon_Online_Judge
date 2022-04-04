#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int	t, m, n;
long long a[1000], b[1000], arr[1000000], brr[1000000], ans = 0;

void input()
{
	cin >> t >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
}

void solution()
{
	int acnt = 0, bcnt = 0;
	arr[acnt++] = 0;
	brr[bcnt++] = 0;
	for (int i = 0; i < m; i++)
	{
		long long sum = a[i];
		arr[acnt++] = sum;
		for (int j = i + 1; j <= i + m - 2; j++)
		{
			sum += a[j % m];
			arr[acnt++] = sum;
		}
	}
	arr[acnt++] = accumulate(a, a + m, 0);

	for (int i = 0; i < n; i++)
	{
		long long sum = b[i];
		brr[bcnt++] = sum;
		for (int j = i + 1; j <= i + n - 2; j++)
		{
			sum += b[j % n];
			brr[bcnt++] = sum;
		}
	}
	brr[bcnt++] = accumulate(b, b + n, 0);

	sort(arr, arr + acnt);
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