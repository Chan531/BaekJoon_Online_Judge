#include <iostream>
#include <algorithm>

using namespace std;

int n, k, arr[5050];	
long long ans;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n, greater<>());

	for (int i = 0; i < k; i++)
		ans += arr[i];

	cout << ans - (k * (k - 1) / 2);
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