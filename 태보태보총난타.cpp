#include <iostream>

using namespace std;

int l, r;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	int idx = 0;

	while (s[idx] != ')')
	{
		if (s[idx++] == '@')
			l++;
	}

	while (idx != s.length())
	{
		if (s[idx++] == '@')
			r++;
	}

	cout << l << ' ' << r;
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