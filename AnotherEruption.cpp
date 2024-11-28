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

	cout << sqrt(n / 3.141592) * 2 * 3.141592;
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