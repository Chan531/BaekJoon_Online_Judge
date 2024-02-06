#include <iostream>

using namespace std;

int n, h, ans;

void input()
{
	cin >> n >> h;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;

		if (m <= h)
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

	solve();
	return 0;
}