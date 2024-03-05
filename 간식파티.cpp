#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1010], dp[1010];

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		dp[i] = arr[i];

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], arr[i] + dp[j]);
		}
	}

	cout << *max_element(dp, dp + n);
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