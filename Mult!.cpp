#include <iostream>

using namespace std;

int n, m, x;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> m;

		if (x == 0)
		{
			x = m;
			continue;
		}

		if (m % x == 0)
		{
			cout << m << '\n';
			x = 0;
		}
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