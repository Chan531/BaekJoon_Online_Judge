#include <iostream>

using namespace std;

int n;
string s = "SciComLove";

void input()
{
	cin >> n;
}

void solution()
{
	n %= 10;
	
	for (int i = 0; i < n; i++)
		s += s[i];

	for (int i = n; i < n + 10; i++)
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

	solve();
	return 0;
}