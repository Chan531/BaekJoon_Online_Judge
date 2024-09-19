#include <iostream>

using namespace std;

int k, n, ans1, ans2, ans3;

void input()
{
	cin >> k >> n;
}

void solution()
{
	cout << k << ' ' << n * (n + 1) / 2 << ' ' << n * n << ' ' << n * n + n << '\n';
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