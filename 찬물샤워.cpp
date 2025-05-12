#include <iostream>
#include <cmath>

using namespace std;

int n, k, ans, d[1010], arr[1010];

void input()
{
	cin >> n >> k >> arr[0];
	for (int i = 1; i <= n; i++) cin >> d[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > k)
			arr[i + 1] = arr[i] + d[i + 1] - abs(arr[i] - k);

		else if (arr[i] < k)
			arr[i + 1] = arr[i] + d[i + 1] + abs(arr[i] - k);

		else
			arr[i + 1] = arr[i] + d[i + 1];
	}

	for (int i = 1; i <= n; i++)
		ans += abs(k - arr[i]);

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