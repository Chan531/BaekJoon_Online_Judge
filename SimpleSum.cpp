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
	if (s[0] - '0' + s[4] - '0' == s[8] - '0')
		cout << "YES";

	else
		cout << "NO";
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