#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll a, b, c, x, y, z, ans;

void input()
{
	cin >> a >> b >> c >> x >> y >> z;
}

void ax()
{
	ans += min(a, x);

	if (a >= x)
	{
		a -= x;
		x = 0;
	}

	else
	{
		x -= a;
		a = 0;
	}
}

void by()
{
	ans += min(b, y);

	if (b >= y)
	{
		b -= y;
		y = 0;
	}

	else
	{
		y -= b;
		b = 0;
	}
}

void cz()
{
	ans += min(c, z);

	if (c >= z)
	{
		c -= z;
		z = 0;
	}

	else
	{
		z -= c;
		c = 0;
	}
}

void solution()
{
	ax();
	by();
	cz();

	if (x >= 3)
	{
		y += x / 3;
		x %= 3;
	}

	by();

	if (y >= 3)
	{
		z += y / 3;
		y %= 3;
	}

	cz();

	if (z >= 3)
	{
		x += z / 3;
		z %= 3;
	}

	ax();

	if (x >= 3)
	{
		y += x / 3;
		x %= 3;
	}

	by();

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