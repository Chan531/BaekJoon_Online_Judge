#include <iostream>

using namespace std;

int n;
string s;

void input()
{
	cin >> s >> n;
}

void solution()
{
	cout << s[n - 1];
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