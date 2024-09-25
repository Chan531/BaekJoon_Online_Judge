#include <iostream>

using namespace std;

int n, ans;
string s, a = "Blackking", b = "Whiteking";

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int k;
		cin >> k;
		ans ^= (k - 2);
	}

	cin >> s;

	if (a == s)
		ans ? cout << a : cout << b;
	else
		ans ? cout << b : cout << a;
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