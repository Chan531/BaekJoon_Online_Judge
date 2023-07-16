#include <iostream>

using namespace std;

int n, m, ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
		cin >> m, ans += m;

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