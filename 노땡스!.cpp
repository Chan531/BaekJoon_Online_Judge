#include <iostream>

using namespace std;

int n, arr[33];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int ans = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - 1 == arr[i - 1])
			continue;

		ans += arr[i];
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