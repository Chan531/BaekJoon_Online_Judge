#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	int d = a + b * c;
	int e = a * b;

	if (d > e)
		cout << 1;

	else if (d == e)
		cout << 0;

	else
		cout << 2;
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