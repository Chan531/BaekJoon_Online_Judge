#include <iostream>

using namespace std;

double n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << fixed;
	cout.precision(1);

	if (n <= 30)
		cout << n / 2;

	else
		cout << 15 + (n - 30) * 3 / 2;
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