#include <iostream>
#include <algorithm>

using namespace std;

int n, maxy = -10, miny = 10, maxx = -10, minx = 10;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		minx = min(minx, a);
		miny = min(miny, b);
		maxx = max(maxx, c);
		maxy = max(maxy, d);
		cout << 2 * (maxy - miny) + 2 * (maxx - minx) << '\n';
	}
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