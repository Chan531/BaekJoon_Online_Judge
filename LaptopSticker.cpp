#include <iostream>

using namespace std;

int a, b, c, d, ans;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	if (a > c + 1 && b > d + 1)
		ans = 1;

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