#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans;

void input()
{
	cin >> n >> m;
}

void solution()
{
	ans = m;

	if (n >= 20)
		ans = min(ans, m / 4 * 3);

	if (n >= 15)
		ans = min(ans, m - 2000);

	if (n >= 10)
		ans = min(ans, m / 10 * 9);

	if (n >= 5)
		ans = min(ans, m - 500);

	if (ans < 0)
		ans = 0;

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