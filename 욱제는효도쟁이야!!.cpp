#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int n, arr[50505];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	cout << accumulate(arr, arr + n, 0) - *max_element(arr, arr + n);
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