#include <iostream>

using namespace std;

int n, m, ans, arr[101], map[101][101];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];
}

void solution()
{
	for (int i = 1; i <= n; i++) ans += map[arr[i - 1]][arr[i]];
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