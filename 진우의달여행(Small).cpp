#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[6][6], ans = 1e9;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
}

void backtrack(int y, int x, int pre, int val)
{
	if (y == n - 1)
	{
		ans = min(ans, val);
		return;
	}

	if (x != 0 && pre != 0)
		backtrack(y + 1, x - 1, 0, val + arr[y + 1][x - 1]);

	if (pre != 1)
		backtrack(y + 1, x, 1, val + arr[y + 1][x]);

	if (x != m - 1 && pre != 2)
		backtrack(y + 1, x + 1, 2, val + arr[y + 1][x + 1]);
}

void solution()
{
	for (int i = 0; i < m; i++)
		backtrack(0, i, -1, arr[0][i]);

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