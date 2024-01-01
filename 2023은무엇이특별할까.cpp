#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	(n + 1) % (n % 100) ? cout << "Bye\n" : cout << "Good\n";
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}