#include <iostream>
#include <algorithm>

using namespace std;

int n, x, arr[101010], ans = 2000000000;

void input()
{
	cin >> n >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i < n; i++)
		ans = min(ans, (arr[i] + arr[i - 1]) * x);

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