#include <iostream>
#include <algorithm>

using namespace std;

int x, y;

void input()
{
	cin >> x >> y;
}

void solution()
{
	cout << x + y + min(x, y) / 10;
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