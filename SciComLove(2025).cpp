#include <iostream>

using namespace std;

int ans;
string s, t = "SciComLove";

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < 10; i++)
		if (s[i] != t[i])
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