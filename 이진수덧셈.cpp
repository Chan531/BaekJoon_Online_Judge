#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	string s, t, ans = "";
	int st = 0, sll = 0, tll = 0;
	cin >> s >> t;
	int sl = s.length() - 1, tl = t.length() - 1;
	while (s[sll] == '0')
		sll++;
	while (t[tll] == '0')
		tll++;
	while (sl >= sll || tl >= tll)
	{
		if (sl < 0)
			s[++sl] = '0';
		if (tl < 0)
			t[++tl] = '0';
		if (s[sl] == '1' && t[tl] == '1')
		{
			if (st)
				ans += '1';
			else
			{
				ans += '0';
				st = 1;
			}
		}
		else if (s[sl] == '0' && t[tl] == '0')
		{
			if (st)
			{
				ans += '1';
				st = 0;
			}
			else
				ans += '0';
		}
		else
		{
			if (st)
				ans += '0';
			else
				ans += '1';
		}
		sl--;
		tl--;
	}
	if (st)
		ans += '1';
	reverse(ans.begin(), ans.end());
	cout << ans;
	if (ans == "")
		cout << 0;
	return 0;
}