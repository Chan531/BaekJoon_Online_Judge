#include <iostream>
#include <cmath>

using namespace std;

int x, l, r, ans, mindif = 1e9;

void input()
{
	cin >> x >> l >> r;
}

void solution()
{
	for (int i = l; i <= r; i++)
	{
		if (mindif > abs(x - i))
		{
			mindif = abs(x - i);
			ans = i;
		}
	}

	cout << ans;
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
	cout.tie(NULL);

	solve();
	return 0;
}