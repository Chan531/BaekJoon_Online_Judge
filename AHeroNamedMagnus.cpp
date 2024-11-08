#include <iostream>

using namespace std;

long long n;

void input()
{
	cin >> n;
}

void solution()
{
	// 1 -> 1, 2 -> 3, 3 -> 5, 4 -> 7, 5 -> 9
	cout << n * 2 - 1 << '\n';
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