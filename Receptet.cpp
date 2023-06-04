#include <iostream>

using namespace std;

int n, ans;

void input()
{
	cin >> n;

	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a < b)
			ans += (b - a) * c;
	}
}

void solution()
{
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