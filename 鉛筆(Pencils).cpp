#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, c, d;

void input()
{
	cin >> n >> a >> b >> c >> d;
}

void solution()
{
	int e = (n % a) ? (n / a + 1) * b : n / a * b;
	int f = (n % c) ? (n / c + 1) * d : n / c * d;
	cout << min(e, f);
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