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
	n % 2 ? cout << 0 : cout << (int) pow(2, n / 2);
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