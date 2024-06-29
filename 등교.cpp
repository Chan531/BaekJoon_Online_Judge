#include <iostream>
#include <algorithm>

using namespace std;

int n, x, ans = -1;

void input()
{
	cin >> n >> x;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a + b <= x)
			ans = max(ans, a);
	}

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