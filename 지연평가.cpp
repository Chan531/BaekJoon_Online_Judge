#include <iostream>

using namespace std;

int q;
long long p, m = 1, cur = 1;

void input()
{
	cin >> q;
}

void solution()
{
	while (q--)
	{
		int c;
		long long x;
		cin >> c;

		if (c == 0)
		{
			cin >> x;
			p += x;
		}

		else if (c == 1)
		{
			cin >> x;
			m *= x;
			p *= x;
		}

		else if (c == 2)
		{
			cin >> x;
			cur += x;
		}

		else
			cout << cur * m + p << '\n';
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