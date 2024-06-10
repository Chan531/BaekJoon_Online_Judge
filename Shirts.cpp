#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
string s;
vector<string> v;

bool cmp(string a, string b)
{
	if (a[0] == b[0])
		return a < b;

	return a > b;
}

void solve()
{
	while (1)
	{
		cin >> n;

		if (!n) break;

		while (n--)
		{
			cin >> s;
			v.push_back(s);
		}

		cin >> m;

		while (m--)
		{
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end(), cmp);

		for (auto i : v)
			cout << i << ' ';

		cout << '\n';

		v.clear();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}