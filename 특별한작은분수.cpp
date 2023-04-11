#include <iostream>

using namespace std;

int x, n;

void input()
{
	cin >> x >> n;
}

void solution()
{
	while (n--)
	{
		if (x % 2)
		{
			x *= 2;
			x ^= 6;
		}

		else
		{
			x /= 2;
			x ^= 6;
		}
	}

	cout << x;
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