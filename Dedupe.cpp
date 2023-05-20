#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	string ans = "";
	ans += s[0];

	for (int i = 1; i < s.length(); i++)
		if (s[i] != s[i - 1])
			ans += s[i];

	cout << ans << '\n';
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