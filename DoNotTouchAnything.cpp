#include <iostream>

using namespace std;

long long r, c, n;

void input()
{
	cin >> r >> c >> n;
}

void solution()
{
	long long ans = 1;

	r % n ? ans *= (r / n) + 1 : ans *= r / n;
	c % n ? ans *= (c / n) + 1 : ans *= c / n;

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