#include <iostream>
#include <cmath>

using namespace std;

int n, idx;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	n = sqrt(s.length());
	idx = n - 1;

	while (idx >= 0)
	{
		for (int i = idx; i < s.length(); i += n)
			cout << s[i];

		idx--;
	}

	cout << '\n';
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