#include <iostream>

using namespace std;

int n, t, c, p;

void input()
{
	cin >> n >> t >> c >> p;
}

void solution()
{
	cout << (n - 1) / t * c * p;
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