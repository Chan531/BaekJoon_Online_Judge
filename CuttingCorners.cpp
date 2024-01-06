#include <iostream>
#include <cmath>

using namespace std;

double a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	cout << fixed;
	cout.precision(8);
	cout << a + b - sqrt(a * a + b * b);
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