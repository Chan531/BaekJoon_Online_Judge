#include <iostream>
#include <algorithm>
#include <numeric>
#define N 101010

using namespace std;

int n;
double arr[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	if (n == 1)
	{
		cout << arr[0];
		return;
	}

	cout << fixed;
	cout.precision(6);

	sort(arr, arr + n);
	cout << max(arr[n - 2], (double) accumulate(arr, arr + n, 0) / n);
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