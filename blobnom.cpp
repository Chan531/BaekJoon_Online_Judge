#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1010100], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	ans = max(arr[0], arr[n - 1]);

	for (int i = 1; i < n - 1; i++)
		ans = max(ans, arr[i] + min(arr[i - 1], arr[i + 1]));

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