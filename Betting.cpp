#include <iostream>

using namespace std;

double a;
double b = 100;

void input()
{
	cin >> a;
}

void solution()
{
	cout << fixed;
	cout.precision(10);

	cout << b / a << '\n' << b / (b - a);
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