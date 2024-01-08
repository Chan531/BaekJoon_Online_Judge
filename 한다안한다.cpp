#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	s[s.length() / 2] == s[(s.length() - 1) / 2] ? cout << "Do-it\n" : cout << "Do-it-Not\n";
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