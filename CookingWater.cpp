#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b = 1010;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int c, d;
		cin >> c >> d;
		a = max(a, c);
		b = min(b, d);
	}

	if (a <= b) cout << "gunilla has a point";
	else cout << "edward is right";
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