#include <iostream>
#include <algorithm>

using namespace std;

double ans = 1e9, p[10];

void input()
{
	for (int i = 0; i < 10; i++) cin >> p[i];
}

void solution()
{
	cout << fixed;
	cout.precision(6);

	sort(p, p + 10);
	
	for (int i = 9; i; i--)
	{
		ans *= p[i];
		ans /= i;
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