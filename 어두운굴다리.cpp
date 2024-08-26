#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans, arr[101010];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> arr[i];
}

void solution()
{
	ans = max(arr[1] - 0, n - arr[m]);

	for (int i = 2; i < m; i++)
		ans = max(ans, (arr[i] - arr[i - 1] + 1) / 2);

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