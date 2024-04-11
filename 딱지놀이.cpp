#include <iostream>
#include <cstring>

using namespace std;

int n, a[5], b[5];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		a[m]++;
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		b[m]++;
	}
}

char battle(int n)
{
	if (n == 0)
		return 'D';

	if (a[n] > b[n])
		return 'A';

	else if (a[n] < b[n])
		return 'B';

	return battle(n - 1);
}

void solution()
{
	cout << battle(4) << '\n';
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
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