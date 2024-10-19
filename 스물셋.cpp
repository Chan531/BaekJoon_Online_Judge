#include <iostream>

using namespace std;

long long n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << n * 23 << '\n';
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