#include <iostream>

using namespace std;

int n, m, ans;

void input()
{
	cin >> n >> m;
}

void solution()
{
	ans += n;

	while (n >= m)
	{
		n /= m;
		ans += n;
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