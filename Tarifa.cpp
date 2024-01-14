#include <iostream>

using namespace std;

int x, n, ans;

void input()
{
	cin >> x >> n;
}

void solution()
{
	ans += (n + 1) * x;

	while (n--)
	{
		int m;
		cin >> m;
		ans -= m;
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