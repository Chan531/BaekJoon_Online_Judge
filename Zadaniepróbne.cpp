#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 2; i >= 0; i--)
		cout << s[i];
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