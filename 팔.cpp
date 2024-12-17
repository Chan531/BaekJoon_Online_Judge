#include <iostream>

using namespace std;

int ans;
string t, l, r;

void input()
{
	cin >> t >> r;
}

void init()
{
	int len = r.length() - t.length();
	while (len--)
		l += "0";
	l += t;
}

void solution()
{
	init();

	bool pre = 1;

	for (int i = 0; i < l.length(); i++)
	{
		if (l[i] == '8' && r[i] == '8' && pre) ans++;
		if (l[i] != r[i]) pre = 0;
	}

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