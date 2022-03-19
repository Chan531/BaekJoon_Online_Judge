#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100001], ans = 0;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr + 1, arr + n + 1, greater<int>());
	for (int i = 1; i <= n; i++)
		ans = max(ans, arr[i] + i);
	cout << ans + 1;
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