#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	a > b ? cout << a * 50 - b * 10 + 500 : cout << a * 50 - b * 10;
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