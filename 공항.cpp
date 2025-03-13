#include <iostream>
#include <set>

using namespace std;

int g, p, ans;
set<int> s;

void input()
{
	cin >> g >> p;
}

void init()
{
	for (int i = 1; i <= g; i++) s.insert(i);
}

void solution()
{
	init();
	
	while (p--)
	{
		int k;
		cin >> k;
		auto it = s.lower_bound(k);
		if (*it == k)
		{
			ans++;
			s.erase(k);
			continue;
		}
		if (it == s.begin()) break;
		ans++;

		s.erase(*--it);
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

	solve();
	return 0;
}