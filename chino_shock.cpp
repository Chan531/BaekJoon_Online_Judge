#include <iostream>

using namespace std;

string s;
int u;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '_')
			u++;

	cout << s.length() + 2 + u * 5;
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
	cout.tie(NULL);

	solve();
	return 0;
}