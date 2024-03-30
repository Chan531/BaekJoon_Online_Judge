#include <iostream>
#include <numeric>
#include <algorithm>
#define N 33333
#define ll long long

using namespace std;

int n;
ll arr[N], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	ans += arr[0] + arr[n - 1] + 2 * n;
	ans += accumulate(arr, arr + n, 0L) * 2;
	
	for (int i = 1; i < n; i++)
		ans += max(arr[i], arr[i - 1]) - min(arr[i], arr[i - 1]);

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