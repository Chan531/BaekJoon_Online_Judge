#include <iostream>
#include <string>

using namespace std;

int n;

void input()
{
	cin >> n;
	cin.ignore();
}

void solution()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (isblank(s[i])) cout << '\n';
		else cout << s[i];
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