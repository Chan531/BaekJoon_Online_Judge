#include <iostream>

using namespace std;

int a, b, l, r;

void input()
{
	cin >> a >> b;
}

void solution()
{
	while (1)
	{
		if (a == 1)
		{
			r += b - a;
			break;
		}

		if (b == 1)
		{
			l += a - b;
			break;
		}

		if (a > b)
		{
			l++;
			a -= b;
		}

		else
		{
			r++;
			b -= a;
		}
	}

	cout << l << ' ' << r;
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