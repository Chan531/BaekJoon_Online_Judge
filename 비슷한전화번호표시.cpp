#include <iostream>
#include <string>

using namespace std;

int ans;
string s, k;

void input()
{
	getline(cin, s);
	cin >> k;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		string str = "";

		while (i < s.length() && s[i] != ' ')
			str += s[i++];

		if (str.substr(0, k.length()) == k && str.length() != k.length()) ans++;
	}

	cout << ans;
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