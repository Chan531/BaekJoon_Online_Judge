#include <iostream>
#include <algorithm>
#include <algorithm>

using namespace std;

int n, arr[1010], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	arr[n] = arr[0];

	for (int i = 0; i < n; i++)
		ans += abs(arr[i] - arr[i + 1]);

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