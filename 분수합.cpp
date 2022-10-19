#include <iostream>

using namespace std;

int a, b, c, d, e, f;

void input()
{
	cin >> a >> b >> c >> d;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	int n = gcd(b, d);

	f = b * (d / n);
	a *= d / n;
	c *= b / n;
	e = a + c;

	int m = gcd(e, f);
	e /= m;
	f /= m;

	cout << e << ' ' << f;
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
	cout.tie(NULL);

	solve();
	return 0;
}