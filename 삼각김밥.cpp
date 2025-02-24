#include <iostream>
#include <algorithm>

using namespace std;

double x, y, ans;
int n;

void input()
{
	cin >> x >> y >> n;
}

void solution()
{
	cout << fixed;
	cout.precision(2);

	ans = x * 1000 / y;
	while (n--)
	{
		double a, b;
		cin >> a >> b;
		ans = min(ans, a * 1000 / b);
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