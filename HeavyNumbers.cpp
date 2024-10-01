#include <iostream>

using namespace std;

int a, b, c, d;

void input()
{
	cin >> a >> b;
}

void solution()
{
	int cnt = 0;

	while (a)
	{
		c += a % 10;
		a /= 10;
		cnt++;
	}

	c *= cnt;
	cnt = 0;

	while (b)
	{
		d += b % 10;
		b /= 10;
		cnt++;
	}

	d *= cnt;

	if (c == d)
		cout << 0;

	else if (c > d)
		cout << 1;

	else cout << 2;
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