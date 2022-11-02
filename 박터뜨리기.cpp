#include <iostream>

using namespace std;

int n, k;

void input()
{
	cin >> n >> k;
}

void solution()
{
	n -= k * (k + 1) / 2;
	n < 0 ? cout << -1 : n % k ? cout << k : cout << k - 1;
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