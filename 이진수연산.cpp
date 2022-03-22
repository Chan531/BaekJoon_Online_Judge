#include <iostream>

using namespace std;

string a, b, ans;

void input()
{
	cin >> a >> b;
}

void solution()
{
	ans = "";

	for (int i = 0; i < a.length(); i++)
		(a[i] == '1' && b[i] == '1') ? ans += '1' : ans += '0';

	cout << ans << '\n';

	ans = "";

	for (int i = 0; i < a.length(); i++)
		(a[i] == '1' || b[i] == '1') ? ans += '1' : ans += '0';

	cout << ans << '\n';

	ans = "";

	for (int i = 0; i < a.length(); i++)
		(a[i] != b[i]) ? ans += '1' : ans += '0';

	cout << ans << '\n';

	ans = "";

	for (int i = 0; i < a.length(); i++)
		a[i] == '0' ? ans += '1' : ans += '0';

	cout << ans << '\n';

	ans = "";

	for (int i = 0; i < b.length(); i++)
		b[i] == '0' ? ans += '1' : ans += '0';

	cout << ans << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}