#include <iostream>

using namespace std;

int n, m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	cout << (n - 1) * (m - 1) * 2;
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