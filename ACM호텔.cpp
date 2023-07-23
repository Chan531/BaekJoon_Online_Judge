#include <iostream>
#include <string>

using namespace std;

int h, w, n;
string ans;

void input()
{
	cin >> h >> w >> n;
}

void solution()
{
	ans = "";

	n% h ? ans += to_string(n % h) : ans += to_string(h);
	(n - 1) / h >= 9 ? ans += "" : ans += '0';
	n% h ? ans += to_string(n / h + 1) : ans += to_string(n / h);

	cout << ans << '\n';
}

void solve()
{
	int tc;
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