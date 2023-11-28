#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n;
ll ans;
vector<ll> p, m;
bool z;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll num;
		cin >> num;

		if (num > 0)
			p.push_back(num);

		else if (num == 0)
			z = 1;

		else
			m.push_back(num);
	}
}

void solution()
{
	sort(p.begin(), p.end());
	sort(m.begin(), m.end(), greater<ll>());

	while (p.size() > 1)
	{
		if (p.back() == 1)
			break;

		ll temp = p.back();
		p.pop_back();

		if (p.back() == 1)
		{
			ans += temp;
			break;
		}

		ans += temp * p.back();
		p.pop_back();
	}

	if (!p.empty())
		p.back() == 1 ? ans += p.size() : ans += p.back();

	while (m.size() > 1)
	{
		ll temp = m.back();
		m.pop_back();
		ans += temp * m.back();
		m.pop_back();
	}

	if (!m.empty() && !z)
		ans += m.back();

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