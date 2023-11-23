#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d, e;

void input()
{
	cin >> a >> b >> c >> d >> e;
}

void solution()
{
	cout << max(0, 4 * e - a - b - c - d);
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