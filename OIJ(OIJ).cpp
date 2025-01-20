#include <iostream>

using namespace std;

int n;
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I') s[i] = 'J';
		else if (s[i] == 'J') s[i] = 'O';
		else s[i] = 'I';
	}

	cout << s;
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