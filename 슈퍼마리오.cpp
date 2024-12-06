#include <iostream>
#include <cmath>

using namespace std;

int ans, arr[11];

void input()
{
	for (int i = 1; i <= 10; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void solution()
{
	for (int i = 1; i <= 10; i++)
	{
		if (abs(100 - ans) >= abs(100 - arr[i]))
			ans = arr[i];
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

	solve();
	return 0;
}