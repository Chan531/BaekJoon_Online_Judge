#include <iostream>
#include <string>

using namespace std;

string s;

void solution()
{
	int idx = 0;
	while (idx < s.length())
	{
		string l = "";

		while (idx != s.length() && s[idx] != ' ')
		{
			l += s[idx++];
		}

		for (int i = l.length() - 1; i >= 0; i--)
			cout << l[i];

		if (idx >= s.length())
			cout << '\n';

		else
			cout << ' ';

		idx++;
	}
}

void solve()
{
	while (1)
	{
		getline(cin, s);

		if (s.length() == 1 && s[0] == '#')
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}