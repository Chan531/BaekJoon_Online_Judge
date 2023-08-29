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
	for (int j = 0; j < n; j++)
		if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
			ans++;
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