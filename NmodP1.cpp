#include <iostream>

using namespace std;

long long n, p, ans = 1;

void input()
{
	cin >> n >> p;
}

void solution()
{
	for (int i = n; i; i--)
	{
		ans *= i;
		ans %= p;
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