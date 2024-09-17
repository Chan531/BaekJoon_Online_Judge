#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long arr[101010];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	while (m--)
	{
		int a;
		long long b, c;
		cin >> a >> b;

		if (a == 1)
			cout << n - (lower_bound(arr, arr + n, b) - arr) << '\n';

		else if (a == 2)
			cout << n - (upper_bound(arr, arr + n, b) - arr) << '\n';

		else
		{
			cin >> c;
			cout << (upper_bound(arr, arr + n, c) - arr) - (lower_bound(arr, arr + n, b) - arr) << '\n';
		}
	}
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