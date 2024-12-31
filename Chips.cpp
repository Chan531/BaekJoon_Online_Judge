#include <iostream>

using namespace std;

int k, n;

void input()
{
	cin >> k >> n;
}

void solution()
{
	cout << n + 1 << ' ' << n * k + 1;
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