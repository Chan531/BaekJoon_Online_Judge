#include <iostream>
#include <algorithm>

using namespace std;

int m, h, n, c, b, ans;

void input()
{
	cin >> m >> h >> n;
}

void solution()
{
	while (n--)
	{
		cin >> c >> b;
		ans += max(c * m, b * h);
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