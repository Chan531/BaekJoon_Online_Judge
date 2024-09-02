#include <iostream>

using namespace std;

int n, k, ans;

void input()
{
	cin >> n >> k;
}

void solution()
{
	ans = 0;

	while (n--)
	{
		int a;
		cin >> a;
		ans += a / k;
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