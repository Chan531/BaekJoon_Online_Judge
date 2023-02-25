#include <iostream>

using namespace std;

string s, p;

void input()
{
	cin >> s >> p;
}

void solution()
{
	int ans = s.length();
	int sl = s.length();
	int pl = p.length();

	if (pl > sl || pl == 1)
		cout << ans << '\n';

	for (int i = 0; i < sl; i++)
	{
		if (s.substr(i, pl) == p)
		{
			ans -= pl - 1;
			i += pl - 1;
		}
	}

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
	cout.tie(NULL);

	solve();
	return 0;
}