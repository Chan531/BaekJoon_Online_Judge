#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[200], dp[200], ans = 0;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] < arr[j])
				dp[j] = max(dp[j], dp[i] + 1);

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
	cout.tie(NULL);

	solve();
	return 0;
}