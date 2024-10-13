#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a, b, x, y;

void input()
{
	cin >> a >> b >> x >> y;
}

void solution()
{
	cout << min({ abs(b - a), abs(x - a) + abs(y - b), abs(a - y) + abs(b - x) });
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