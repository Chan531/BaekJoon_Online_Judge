#include <iostream>

using namespace std;

string s;
int n;

void input()
{
	cin >> s;
}

void solution()
{
	n += (s[0] - '0') * 2;

	int m = 7;

	for (int i = 1; i < 7; i++)
	{
		n += (s[i] - '0') * m;
		m--;
	}

	n %= 11;

	if (n >= 1 && n <= 9) cout << (char) ('A' + n - 1);
	else if (n == 0) cout << 'J';
	else cout << 'Z';
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