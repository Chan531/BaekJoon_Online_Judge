#include <iostream>

using namespace std;

int n, m, x, y, c;

void input()
{
	cin >> m >> n;
}

bool move(int k)
{
	if (c == 0)
		x += k;

	if (c == 1)
		y += k;

	if (c == 2)
		x -= k;

	if (c == 3)
		y -= k;

	if (x >= 0 && x <= m && y >= 0 && y <= m)
		return 1;

	return 0;
}

void solution()
{
	while (n--)
	{
		string s;
		int k;
		cin >> s >> k;

		if (s == "MOVE")
		{
			if (!move(k))
			{
				x = -1;
				break;
			}
		}

		else
		{
			if (!k)
				c++;

			else
				c--;

			c += 4;
			c %= 4;
		}
	}

	if (x == -1)
		cout << x;

	else
		cout << x << ' ' << y;
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