#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, a, b, c, ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

void input()
{
	cin >> s;
}

string check()
{
	string ret = "";

	for (int i = a.length() - 1; i >= 0; i--)
		ret += a[i];	
	for (int i = b.length() - 1; i >= 0; i--)
		ret += b[i];	
	for (int i = c.length() - 1; i >= 0; i--)
		ret += c[i];

	return ret;
}

void solution()
{
	for (int i = 1; i <= s.length() - 2; i++)
	{
		a = s.substr(0, i);
		for (int j = 1; j <= s.length() - i - 1; j++)
		{
			b = s.substr(i, j);
			c = s.substr(i + j, s.length() - i - j);
			ans = min(ans, check());
		}
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