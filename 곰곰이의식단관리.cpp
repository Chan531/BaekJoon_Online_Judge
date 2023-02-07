#include <iostream>

using namespace std;

int n;
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	int c = 0;

	for (int i = 0; i < n; i++)
		if (s[i] == 'C')
			c++;

	c % (n - c + 1) ? cout << c / (n - c + 1) + 1 : cout << c / (n - c + 1);
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