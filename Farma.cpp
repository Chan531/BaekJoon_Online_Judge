#include <iostream>

using namespace std;

int n, m, x, y;

void input()
{
	cin >> n >> m;
}

void solution()
{
	y = (m - 2 * n) / 2;
	x = n - y;
	cout << x << ' ' << y;
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