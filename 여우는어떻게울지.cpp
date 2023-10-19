#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string str;
unordered_map<string, int> say;

void input()
{
	getline(cin, str);
}

void solution()
{
	while (1)
	{
		string s;
		getline(cin, s);

		if (s == "what does the fox say?")
			break;

		int idx = 0, cnt = 0;

		while (1)
		{
			if (cnt == 2)
				break;

			if (s[idx] == ' ')
				cnt++;

			idx++;
		}

		string t = "";

		while (idx < s.length())
			t += s[idx++];

		say[t] = 1;
	}

	int idx = 0;

	while (idx < str.length())
	{
		string s = "";

		while (idx < str.length() && str[idx] != ' ')
			s += str[idx++];

		if (!say[s])
			cout << s << ' ';

		idx++;
	}

	cout << '\n';
	say.clear();
}

void solve()
{
	int tc;
	cin >> tc;
	cin.ignore();

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