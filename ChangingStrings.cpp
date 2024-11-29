#include <iostream>

using namespace std;

int sp, ep;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U')
		{
			sp = i;
			break;
		}
	}

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == 'F')
		{
			ep = i;
			break;
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (sp > i || i > ep) cout << "-";
		else if (i == sp) cout << "U";
		else if (i == ep) cout << "F";
		else cout << "C";
	}
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