#include <iostream>

using namespace std;

int ans;
string s;

void input()
{
	cin >> s;
}

void solution()
{
	ans = 0;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'D')
			break;

		ans++;
	}

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