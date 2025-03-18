#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	a *= 2;
	a--;
	cout << max(0, (c - b) * a) << '\n';
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