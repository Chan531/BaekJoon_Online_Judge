#include <iostream>
#include <algorithm>
#define p pair<long long ,int>

using namespace std;

int n;
long long arr[1000000];
p sortarr[1000000];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sortarr[i].first = arr[i];
		sortarr[i].second = i;
	}
}

void solution()
{
	sort(sortarr, sortarr + n, greater<p>());

	int idx = 0, cnt = 0;
	long long sum = 0, ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (idx >= n)
			break;

		if (i == sortarr[idx].second)
		{
			ans += sortarr[idx].first * cnt - sum;
			sum = 0;
			cnt = 0;

			while (i >= sortarr[idx].second)
				idx++;

			continue;
		}

		sum += arr[i];
		cnt++;
	}

	cout << ans << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}