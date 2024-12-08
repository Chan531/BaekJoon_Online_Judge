#include <iostream>

using namespace std;

int n, arr[2020], dp[2020];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + 1);

	cout << n - *max_element(dp, dp + n) - 1;
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