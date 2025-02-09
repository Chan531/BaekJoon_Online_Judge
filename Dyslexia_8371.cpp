#include <iostream>

using namespace std;

int n, ans;
string s, t;

void input()
{
	cin >> n >> s >> t;
}

void solution()
{
	for (int i = 0; i < n; i++)
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