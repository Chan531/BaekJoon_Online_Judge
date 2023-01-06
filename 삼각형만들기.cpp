#include <iostream>
#include <algorithm>
#define N 1000000

using namespace std;

int n, arr[N], ans = -1;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; i++)
		if (arr[i] + arr[i + 1] > arr[i + 2])
			ans = max(ans, arr[i] + arr[i + 1] + arr[i + 2]);


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