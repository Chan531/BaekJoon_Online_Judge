#include <iostream>

using namespace std;

int a, b, c, p, m;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	p = b - a;

	if (a != 0)
		m = b / a;

	if (c - b == p)
		cout << "AP " << c + p << '\n';
	else
		cout << "GP " << c * m << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (!a && !b && !c)
			break;

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