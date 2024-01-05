#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s, ans = "zzz";

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> s;

		if (s.length() != 3)
			continue;

		ans = min(s, ans);
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