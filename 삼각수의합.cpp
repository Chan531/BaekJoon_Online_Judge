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

	for (int i = 1; i <= n; i++)
		ans += ((i + 1) * (i + 2) / 2) * i;

	cout << ans << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}