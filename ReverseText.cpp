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
	while (n--)
	{
		string s;
		getline(cin, s);

		for (int i = s.length() - 1; i >= 0; i--)
			cout << s[i];

		cout << '\n';
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