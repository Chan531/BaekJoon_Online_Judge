#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int n;

void input()
{
	cin >> s >> n;
	cin.ignore();
}

void solution()
{
	vector<string> v;

	while (n--)
	{
		int idx = 0;
		string t, r = "";
		getline(cin, t);

		r.push_back(t[0]);

		while (idx < t.length())
			if (t[idx++] == ' ')
				r.push_back(t[idx]);

		if (r == s)
			v.push_back(t);
	}

	cout << s << '\n';

	for (auto i : v)
		cout << i << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}