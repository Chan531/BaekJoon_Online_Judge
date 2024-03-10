#include <iostream>
#include <algorithm>

using namespace std;

int n, a = 1e9, b = 1e9, c = -1e9, d = -1e9;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int m, k;
		cin >> m >> k;;

		a = min(a, m);
		b = min(b, k);
		c = max(c, m);
		d = max(d, k);
	}

	cout << (c - a) * (d - b);
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