#include <iostream>

using namespace std;

int s, c, n, m;

void input()
{
	cin >> s >> n >> m;
}

void solution()
{
	for (int i = 0; i < n + m; i++)
	{
		int a;
		cin >> a;

		if (a)
		{
			c++;

			if (c > s)
				s *= 2;
		}

		else
			c--;
	}

	cout << s;
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