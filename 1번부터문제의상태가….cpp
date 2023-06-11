#include <iostream>
#include <regex>

using namespace std;

string s;
int cnt[26];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		cnt[s[i] - 'A']++;

	if (cnt[0])
	{
		s = regex_replace(s, regex("B"), "A");
		s = regex_replace(s, regex("C"), "A");
		s = regex_replace(s, regex("D"), "A");
		s = regex_replace(s, regex("F"), "A");
	}

	else if (cnt[1])
	{
		s = regex_replace(s, regex("C"), "B");
		s = regex_replace(s, regex("D"), "B");
		s = regex_replace(s, regex("F"), "B");
	}

	else if (cnt[2])
	{
		s = regex_replace(s, regex("D"), "C");
		s = regex_replace(s, regex("F"), "C");
	}

	else
		for (int i = 0; i < s.length(); i++)
			s[i] = 'A';

	cout << s;
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