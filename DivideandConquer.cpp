#include <iostream>

using namespace std;

int n, m, x, y;

void input()
{
	cin >> m >> n;
}

void solution()
{
	while (m <= n)
	{
		int cnt = 2;

		for (int i = 2; i < m; i++)
			if (!(m % i))
				cnt++;

		if (y <= cnt)
		{
			x = m;
			y = cnt;
		}

		m++;
	}

	cout << x << ' ' << y << '\n';
}

void solve()
{
	while (1)
	{
		input();
		if (!m && !n) break;
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}