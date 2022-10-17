#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001], ans;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void solution()
{
	ans = -1000;

	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = max(ans, arr[j] - arr[i]);

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