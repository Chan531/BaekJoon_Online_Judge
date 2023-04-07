#include <iostream>

using namespace std;

int n, d, p;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		char c;
		cin >> c;

		if (c == 'D')
			d++;

		else
			p++;

		if (d - p >= 2 || p - d >= 2)
		{
			cout << d << ':' << p;
			return;
		}
	}

	cout << d << ':' << p;
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