#include <iostream>

using namespace std;

int ans, cnt, tc;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	ans = 1;
	cnt = 0;

	for (int i = 0; ; i++) {
		cnt++;
		if (i >= s.length() - 1 - i) break;
		if (s[i] != s[s.length() - 1 - i]) {
			ans = 0;
			break;
		}
	}
	cout << ans << ' ' << cnt << '\n';
}

void solve()
{
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