#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b = 1e9;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int c, d;
		cin >> c >> d;

		b = min(b, d);

		if (b == d)
			a = c;
	}

	cout << a << ' ' << b;
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