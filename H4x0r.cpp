#include <iostream>

using namespace std;

string s, ans;

void input()
{
	cin >> s;
}

char check(char c)
{
	if (c == 'a')
		return '4';

	else if (c == 'e')
		return '3';

	else if (c == 'i')
		return '1';

	else if (c == 'o')
		return '0';

	else if (c == 's')
		return '5';

	return c;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		ans += check(s[i]);

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