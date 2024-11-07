#include <iostream>
#include <algorithm>

using namespace std;

double n, ans = 100.0;

void input()
{
	cin >> n;
}

void solution()
{
	cout << fixed;
	cout.precision(2);

	ans = max(ans, n * 0.01 + 25);
	ans = min(ans, 2000.00);
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