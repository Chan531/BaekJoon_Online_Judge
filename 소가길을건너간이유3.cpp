#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, ans = 0;
p arr[100];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (ans < arr[i].first)
			ans = arr[i].first;

		ans += arr[i].second;
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