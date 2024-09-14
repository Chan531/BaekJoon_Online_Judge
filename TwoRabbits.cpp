#include <iostream>

using namespace std;

int a, b, c, d;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	if ((b - a) % (c + d))
		cout << -1 << '\n';

	else
		cout << (b - a) / (c + d) << '\n';
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