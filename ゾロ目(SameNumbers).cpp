#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	(n / 10 == n % 10) ? cout << 1 : cout << 0;
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