#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{
	cin >> s;
}

bool pal(string s)
{
	int len = s.length();
	int idx = len - 1;

	if (idx == 0)
		return true;

	for (int i = 0; i < len; i++)
	{
		if (s[i] != s[idx--])
			return false;
	}

	return pal(s.substr(0, len / 2));
}

void solution()
{
	pal(s) ? cout << "AKARAKA" : cout << "IPSELENTI";
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
	cout.tie(NULL);

	solve();
	return 0;
}