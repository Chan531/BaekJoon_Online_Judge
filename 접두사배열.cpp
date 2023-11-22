#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		cout << i << '\n';
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