#include <iostream>
#include <cmath>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n == 1)
		cout << 0;

	else if (n == 2)
		cout << 2;

	else
		cout << 2 * pow(3, n - 2);
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