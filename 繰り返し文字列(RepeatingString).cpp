#include <iostream>

using namespace std;

int n;
string s, ans = "Yes";

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() / 2 + i])
		{
			ans = "No";
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