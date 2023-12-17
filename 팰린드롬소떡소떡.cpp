#include <iostream>

using namespace std;

int n, ans;
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - 1 - i])
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