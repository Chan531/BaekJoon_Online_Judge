#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

void input()
{
	cin >> s;
}

bool check(string t)
{
	string temp = s + t;
	int sidx = 0, tidx = temp.length() - 1;

	while (sidx < s.length())
		if (s[sidx++] != temp[tidx--])
			return 0;

	return 1;
}

void solution()
{
	for (int i = 0; i <= s.length(); i++)
	{
		string temp = s.substr(0, i);
		reverse(temp.begin(), temp.end());
		
		if (check(temp))
		{
			cout << s << temp << '\n';
			break;
		}
	}
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
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