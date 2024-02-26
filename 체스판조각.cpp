#include <iostream>

using namespace std;

int n, ans = 1;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		ans += (i / 2) + 1;

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