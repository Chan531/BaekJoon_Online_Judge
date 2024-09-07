#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

void input()
{
	cin >> n >> m >> k;
}

void solution()
{
	while (k--)
	{
		int a;
		cin >> a;
		cout << a << ' ' << min(a, 1000) * n + max(0, a - 1000) * m << '\n';
	}
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