#include <iostream>
#include <cstring>

using namespace std;

int a, b, ans;
bool c[1 << 10];

void input()
{
	cin >> a >> b;
}

void solution()
{
	ans = 1;

	while (a != 1)
	{
		c[a] = 1;
		a /= 2;
	}

	while (b != 1)
	{
		if (c[b])
		{
			ans = b;
			break;
		}

		b /= 2;
	}

	cout << ans * 10 << '\n';
	memset(c, 0, 1 << 10);
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
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