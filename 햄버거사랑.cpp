#include <iostream>
#include <algorithm>

using namespace std;

int n, m, t, ans1, ans2;

void input()
{
	cin >> n >> m >> t;
}

void solution()
{
	ans2 = t;

	if (n > m) swap(n, m);

	for (int i = t / n; i >= 0; i--)
	{
		int a = t - n * i;
		int b = a / m;
		int c = a % m;

		if (ans2 > c)
		{
			ans1 = i + b;
			ans2 = c;
		}

		else if (ans2 == c)
			ans1 = max(ans1, i + b);
	}

	cout << ans1 << ' ' << ans2;
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