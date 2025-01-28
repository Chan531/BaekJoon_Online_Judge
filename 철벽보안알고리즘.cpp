#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, idx;
string s, ans[1010];
unordered_map<string, int> m;
unordered_map<int, int> p;

void input()
{
	cin >> n;
}

void solution()
{
	cin.ignore();
	getline(cin, s);
	idx = 1;

	for (int i = 0; i < s.length(); i++)
	{
		string str = "";
		while (i < s.length() && s[i] != ' ')
			str += s[i++];
		m[str] = idx++;
	}

	getline(cin, s);
	idx = 1;

	for (int i = 0; i < s.length(); i++)
	{
		string str = "";
		while (i < s.length() && s[i] != ' ')
			str += s[i++];
		p[idx++] = m[str];
	}

	getline(cin, s);
	idx = 1;

	for (int i = 0; i < s.length(); i++)
	{
		string str = "";
		while (i < s.length() && s[i] != ' ')
			str += s[i++];
		ans[p[idx++]] = str;
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';

	cout << '\n';
}

void reset()
{
	m.clear();
	p.clear();
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
		reset();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}