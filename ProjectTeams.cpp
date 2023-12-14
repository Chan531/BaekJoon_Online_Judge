#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[10010], ans = 1e9;

void input()
{
	cin >> n;

	n *= 2;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);
	
	for (int i = 0; i < n / 2; i++)
		ans = min(ans, arr[i] + arr[n - 1 - i]);

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