#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	ans = n;

	while (n != 1)
	{
		if (n % 2)
			n *= 3, n++;

		else
			n /= 2;

		ans = max(ans, n);
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