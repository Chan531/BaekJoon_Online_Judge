#include <iostream>

using namespace std;

int n;
long long o, e;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		long long m;
		cin >> m;

		m % 2 ? o += m : e += m;
	}

	if (o > e)
		cout << "ODD\n";

	else if (o == e)
		cout << "TIE\n";

	else
		cout << "EVEN\n";

	e = 0;
	o = 0;
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