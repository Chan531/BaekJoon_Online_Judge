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
	cout << s[0];

	for (int i = 1; i < s.length(); i++)
		if (s[i] != s[i - 1])
			cout << s[i];
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