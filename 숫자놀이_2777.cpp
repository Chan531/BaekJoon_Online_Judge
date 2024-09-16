#include <iostream>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	ans = 0;

	if (n == 1)
	{
		cout << 1 << '\n';
		return;
	}

	for (int i = 9; i > 1; i--)
	{
		while (!(n % i))
		{
			n /= i;
			ans++;
		}
	}

	if (n != 1)
		cout << -1 << '\n';
	else
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