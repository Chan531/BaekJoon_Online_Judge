#include <iostream>

using namespace std;

int n, arr[1010101];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int dif = arr[1] - arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - arr[i - 1] != dif) break;
		if (i == n - 1)
		{
			cout << arr[i] + dif;
			return;
		}
	}

	int div = arr[1] / arr[0];
	cout << arr[n - 1] * div;
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