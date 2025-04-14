#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, ans = 1e9;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	ans = min(ans, b * 2 + c * 4);
	ans = min(ans, a * 2 + c * 2);
	ans = min(ans, a * 4 + b * 2);
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