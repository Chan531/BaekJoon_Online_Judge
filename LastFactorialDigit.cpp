#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	int ans = 1;

	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= 10;
	}

	cout << ans << '\n';
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