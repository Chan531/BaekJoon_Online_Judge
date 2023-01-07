#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a, b, n, arr[5], ans = 1e9;

void input()
{
	cin >> a >> b >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	ans = min(ans, abs(a - b));

	for (int i = 0; i < n; i++)
		ans = min(ans, abs(arr[i] - b) + 1);

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