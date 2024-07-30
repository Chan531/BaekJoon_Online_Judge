#include <iostream>

using namespace std;

int n, ans = 1;
char c = ' ';

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		char a;
		cin >> a;

		if (a != c)
			ans++;

		c = a;
	}

	cout << ans;
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