#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[10000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	prev_permutation(arr, arr + n);

	if (n == 1)
	{
		cout << -1;
		return;
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
			break;

		if (i == n - 1)
		{
			cout << -1;
			return;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
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