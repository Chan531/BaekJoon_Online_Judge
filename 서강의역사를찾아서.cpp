#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans, arr[1010];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] *= -1;
	}

	for (int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		arr[i] += k;
	}
}

void solution()
{
	for (int i = 1; i <= max(n, m); i++)
		ans = max(ans, arr[i]);

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