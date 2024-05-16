#include <iostream>

using namespace std;

string s, k, t;
int ans;

void input()
{
	cin >> s >> k;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		if (isalpha(s[i]))
			t += s[i];

	if (t.length() < k.length())
	{
		cout << 0;
		return;
	}

	for (int i = 0; i <= t.length() - k.length(); i++)
	{
		if (t.substr(i, k.length()) == k)
		{
			ans = 1;
			break;
		}
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