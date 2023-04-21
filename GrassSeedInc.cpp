#include <iostream>

using namespace std;

int l;
double n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	cin >> l;

	while (l--)
	{
		double a, b;
		cin >> a >> b;

		ans += a * b;
	}

	cout << fixed;
	cout.precision(8);
	cout << ans * n;
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