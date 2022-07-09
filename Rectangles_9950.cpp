#include <iostream>

using namespace std;

int a, b, c;

void solution()
{
	if (a == 0)
	{
		cout << c / b << ' ' << b << ' ' << c;
		return;
	}

	if (b == 0)
	{
		cout << a << ' ' << c / a << ' ' << c;
		return;
	}

	cout << a << ' ' << b << ' ' << a * b;
}

void solve()
{
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
			break;

		solution();
		cout << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}