#include <iostream>

using namespace std;

double a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << fixed;
	cout.precision(1);

	cout << a * b / 2;
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