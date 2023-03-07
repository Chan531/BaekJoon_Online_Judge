#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> word;

void input()
{
	getline(cin, s);
}

void solution()
{
	int idx = 0;
	string t = "";

	while (idx < s.length())
	{
		while (idx < s.length() && s[idx] != ' ')
		{
			t += s[idx++];
		}

		word.push_back(t);
		t = "";
		idx++;
	}

	for (int i = 2; i < word.size(); i++)
		cout << word[i] << ' ';

	cout << word[0] << ' ' << word[1] << '\n';
	word.clear();
}

void solve()
{
	int testcase;
	cin >> testcase;
	cin.ignore();

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
	cout.tie(NULL);

	solve();
	return 0;
}