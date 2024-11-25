#include <iostream>
#include <cmath>

using namespace std;

long long n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << fixed;
	cout.precision(6);
	double l = sqrt(2 * n / (3 * sqrt(3)));
	cout << l * 6;
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