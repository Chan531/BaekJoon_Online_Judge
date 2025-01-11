#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, a, k;

void input()
{
	cin >> n >> m >> a >> k;
}

void solution()
{
	long long cnt = n * m - a - (m - k);
	long long l = min(n, n - (cnt - (n - 1) * (m - 1)));
	long long r = n - cnt / m;
	cout << l << ' ' << r;
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