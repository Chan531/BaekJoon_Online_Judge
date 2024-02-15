#include <iostream>
#include <cmath>

using namespace std;

int a, b, n, ans = 1e9, x, y;

void input()
{
	cin >> a >> b >> n;
}

void solution()
{
	while (n--)
	{
		int c, d;
		cin >> c >> d;

		if (ans > abs(c - a) + abs(d - b))
		{
			ans = abs(c - a) + abs(d - b);
			x = c;
			y = d;
		}
	}

	cout << x << ' ' << y;
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