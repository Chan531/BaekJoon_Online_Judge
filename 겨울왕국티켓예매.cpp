#include <iostream>

using namespace std;

int n, m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	if (n < 12 || m < 4)
		cout << -1 << '\n';

	else
		cout << 11 * m + 4 << '\n';
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