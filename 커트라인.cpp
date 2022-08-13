#include <iostream>
#include <algorithm>

using namespace std;

int n, k, arr[1000];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	cout << arr[n - k];
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