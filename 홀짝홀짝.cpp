#include <iostream>

using namespace std;

int n, o, e;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		char c;
		cin >> c;
		(c % 2) ? o++ : e++;
	}

	if (o > e)
		cout << 1;

	else if (o == e)
		cout << -1;

	else
		cout << 0;
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