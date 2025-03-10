#include <iostream>

using namespace std;

int n;
long long ans = 1, m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (n--)
	{
		long long k;
		cin >> k;
		ans *= k;
		ans %= m;
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