#include <iostream>
#include <cmath>

using namespace std;

int n, m, ans;

void input()
{
	cin >> n >> m;
}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;

	return gcd(b, a % b);
}

void solution()
{
	int a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (i == 0)
			ans = abs(a - m);

		ans = gcd(abs(a - m), ans);
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
	cout.tie(NULL);

	solve();
	return 0;
}