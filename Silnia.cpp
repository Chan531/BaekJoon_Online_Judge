#include <iostream>

using namespace std;

int n, ans = 1;

void input()
{
	cin >> n;
}

void solution()
{
	if (n >= 5)
	{
		cout << 0;
		return;
	}

	for (int i = 2; i <= n; i++)
	{
		ans *= i;
		ans %= 10;
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