#include <iostream>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	ans = n * 5 - 400;

	cout << ans << '\n';

	if (ans < 100)
		cout << 1;

	else if (ans == 100)
		cout << 0;

	else
		cout << -1;
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