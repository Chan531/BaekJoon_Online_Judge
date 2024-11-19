#include <iostream>

using namespace std;

int n, b, k, ans, arr[101];

void input()
{
	cin >> n >> k >> b;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void solution()
{
	for (int i = b; i < b + k; i++)
	{
		if (i % n)
			ans += arr[i % n];
		else
			ans += arr[n];
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