#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n;
ll d, ans;
vector<ll> m, p;

void input()
{
	cin >> n >> d;

	for (int i = 0; i < n; i++)
	{
		ll k;
		cin >> k;

		if (k > 0)
			p.push_back(k);

		else if (k < 0)
			m.push_back(k);
	}
}

void solution()
{
	m.push_back(0);
	p.push_back(0);

	sort(m.begin(), m.end());
	sort(p.begin(), p.end());

	ans = (2 * m[0] * -1) + 2 * p.back() + 2 * d;
	ans = min(ans, (4 * m[0] * -1) + 2 * p.back() + d);
	ans = min(ans, (2 * m[0] * -1) + 4 * p.back() + d);
	ll val = d + (2 * m[0]) - (2 * p.back());
	if (val < 0) val = 0;
	ans = min(ans, (4 * m[0] * -1) + 4 * p.back() + val);

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