#include <iostream>

using namespace std;

int ans;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i <= s.length() - 4; i++)
		if (s.substr(i, 4) == "kick")
			ans++;

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