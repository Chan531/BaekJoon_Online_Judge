#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

ll x, y, w, s;

void input()
{
	cin >> x >> y >> w >> s;
}

void solution()
{
	ll ans = min(min(x, y) * s, min(x, y) * 2 * w);
	if (abs(x - y) % 2) ans += (abs(x - y) - 1) * min(w, s) + w;
	else ans += abs(x - y) * min(w, s);
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

	solve();
	return 0;
}