#include <iostream>

using namespace std;

int n, a, b, c;
long long ans = 1;

void input()
{
	cin >> n >> a >> b >> c;
}

void solution()
{
	for (int i = n; i > n - a; i--)
		ans *= i;

	for (int i = 2; i <= a; i++)
		ans /= i;

	n -= a;

	for (int i = n; i > n - b; i--)
		ans *= i;

	for (int i = 2; i <= b; i++)
		ans /= i;

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