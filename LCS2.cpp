#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string s, t, l = "";
	cin >> s >> t;
	int sl = s.length() - 1, tl = t.length() - 1;
	vector<vector<int>> v(sl + 1, vector<int>(tl + 1));
	for (int i = 0; i <= sl; i++)
	{
		if (t[0] == s[i])
			v[i][0] = 1;
		else
		{
			if (i > 0)
				v[i][0] = v[i - 1][0];
			else
				v[i][0] = 0;
		}
	}
	for (int i = 0; i <= tl; i++)
	{
		if (s[0] == t[i])
			v[0][i] = 1;
		else
		{
			if (i > 0)
				v[0][i] = v[0][i - 1];
			else
				v[0][i] = 0;
		}
	}
	for (int i = 1; i <= sl; i++)
	{
		for (int j = 1; j <= tl; j++)
		{
			if (s[i] == t[j])
				v[i][j] = v[i - 1][j - 1] + 1;
			else
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
		}
	}
	cout << v[sl][tl] << '\n';
	while (v[sl][tl] > 0)
	{
		while (tl > 0 && v[sl][tl] == v[sl][tl - 1])
			tl--;
		if (sl == 0)
		{
			l += t[tl];
			break;
		}
		if (v[sl - 1][tl] != v[sl][tl])
			l += t[tl];
		sl--;
	}
	reverse(l.begin(), l.end());
	cout << l;
	return 0;
}