#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[10000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	int ans = 0;
	int num = arr[0];
	int idx;

	for (idx = 2; idx < n; idx += 2)
	{
		ans = max(arr[idx] - num, ans);
		num = arr[idx];
	}

	if (n % 2)
	{
		num = arr[n - 2];
		idx = n - 2;
	}

	else
	{
		num = arr[n - 1];
		idx = n - 1;
	}

	for (int i = idx - 2; i > 0; i -= 2)
	{
		ans = max(num - arr[i], ans);
		num = arr[i];
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