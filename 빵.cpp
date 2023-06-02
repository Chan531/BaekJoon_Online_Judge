#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, ans = 1e9;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> a >> b;

		if (a > b)
			continue;

		ans = min(ans, b);
	}

	ans == 1e9 ? cout << -1 : cout << ans;
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