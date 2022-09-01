#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << (n + 1) * 2 << ' ' << (n + 1) * 3;
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