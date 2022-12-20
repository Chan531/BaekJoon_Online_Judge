#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	a = 100 - a;
	b = 100 - b;

	int c = 100 - (a + b);
	int d = a * b;
	int q = d / 100;
	int r = d % 100;

	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
	cout << c + q << ' ' << r;
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