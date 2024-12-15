#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{
	getline(cin, s);
}

void solution()
{
	if (s[0] == '\"' && s[s.length() - 1] == '\"')
	{
		if (s.length() <= 2)
		{
			cout << "CE";
			return;
		}

		int cnt = 0;

		for (int i = 1; i < s.length() - 1; i++)
		{
			if (s[i] == ' ') cnt++;
		}

		if (cnt == s.length() - 2)
		{
			cout << "CE";
			return;
		}

		for (int i = 1; i < s.length() - 1; i++)
			cout << s[i];
	}
	else cout << "CE";
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