#include <iostream>

using namespace std;

int a, b, c, d;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	if (a == 0 && b == 0 && c == 0 && d == 0)
		exit(0);

	if (a == 0)
		cout << d / b / c << ' ' << b << ' ' << c << ' ' << d << '\n';

	else if (b == 0)
		cout << a << ' ' << d / a / c << ' ' << c << ' ' << d << '\n';

	else if (c == 0)
		cout << a << ' ' << b << ' ' << d / a / b << ' ' << d << '\n';

	else
		cout << a << ' ' << b << ' ' << c << ' ' << a * b * c << '\n';
}

void solve()
{
	while (1)
	{
		input();
		solution();
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