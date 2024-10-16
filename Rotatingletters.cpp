#include <iostream>

using namespace std;

string s, ans = "YES";

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'I' || s[i] == 'O' || s[i] == 'S' || s[i] == 'H' || s[i] == 'Z' || s[i] == 'X' || s[i] == 'N') continue;
		ans = "NO";
		break;
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