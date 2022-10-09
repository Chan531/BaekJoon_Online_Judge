#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, c;

void input()
{
	cin >> n;
}

void solution()
{
	int aa, bb, cc;

	while (n--)
	{
		cin >> aa >> bb >> cc;

		a += aa;
		b += bb;
		c += cc;

		if (a >= 30 && b >= 30 && c >= 30)
		{
			int num = min({ a,b,c });
			cout << num << '\n';

			a -= num;
			b -= num;
			c -= num;
		}

		else
			cout << "NO\n";
	}
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