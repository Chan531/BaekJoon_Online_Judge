#include <iostream>

using namespace std;

int n, k, arr[10], ans;

void input()
{
	cin >> n >> k;

	for (int i = n - 1; i >= 0; i--)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		ans += k / arr[i];
		k -= (k / arr[i]) * arr[i];
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