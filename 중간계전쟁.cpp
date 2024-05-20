#include <iostream>

using namespace std;

int tc, a[6] = { 1, 2, 3, 3, 4, 10 }, b[7] = { 1, 2, 2, 2, 3, 5, 10 }, c, d;

void input()
{
	for (int i = 0; i < 6; i++)
	{
		int e;
		cin >> e;
		c += a[i] * e;
	}

	for (int i = 0; i < 7; i++)
	{
		int e;
		cin >> e;
		d += b[i] * e;
	}
}

void solution()
{
	if (c > d)
		cout << "Good triumphs over Evil\n";

	else if (c < d)
		cout << "Evil eradicates all trace of Good\n";

	else
		cout << "No victor on this battle field\n";

	c = 0;
	d = 0;
}

void solve()
{
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		cout << "Battle " << i << ": ";
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