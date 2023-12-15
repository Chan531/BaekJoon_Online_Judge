#include <iostream>

using namespace std;

int n, d;

void input()
{
	cin >> n >> d;
}

void solution()
{
	int ans = 0;

	while (n--)
	{
		double v, f, c;
		cin >> v >> f >> c;

		if (v * (f / c) >= d)
			ans++;
	}

	cout << ans << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}