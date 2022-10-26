#include <iostream>

using namespace std;

int a, b, n, m, ans;

void input()
{
	cin >> a >> b >> n;
}

void solution()
{
	while (n--)
	{
		cin >> m;

		if (m >= a && m <= b)
			ans++;
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