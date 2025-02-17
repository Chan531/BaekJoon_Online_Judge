#include <iostream>
#include <string>

using namespace std;

int n;
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	if (s[n - 1] == 'G') cout << s.substr(0, n - 1);
	else cout << s + "G";
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