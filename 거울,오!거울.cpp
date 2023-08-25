#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{
	getline(cin, s);
}

void solution()
{
	for (int i = s.length() - 1; i >= 0; i--)
		cout << s[i];

	cout << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (s == "***")
			break;

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