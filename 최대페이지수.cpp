#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[2][20], ans;
bool check[20];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> arr[0][i] >> arr[1][i];
}

void backtrack(int idx, int day, int val)
{
	if (day > n)
		return;

	ans = max(ans, val);

	for (int i = idx; i < m; i++)
	{
		check[i] = 1;
		backtrack(i + 1, day + arr[0][i], val + arr[1][i]);
		check[i] = 0;
	}
}

void solution()
{
	backtrack(0, 0, 0);
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