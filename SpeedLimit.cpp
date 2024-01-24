#include <iostream>

using namespace std;

int n, pre, ans;

void input()
{
	cin >> n;
}

void solution()
{
	pre = 0;
	ans = 0;

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		ans += a * (b - pre);
		pre = b;
	}

	cout << ans << " miles\n";
}

void solve()
{
	while (1)
	{
		input();

		if (n == -1)
			return;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}