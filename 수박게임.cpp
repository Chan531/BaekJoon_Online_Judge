#include <iostream>
#include <cmath>

using namespace std;

int n, k;

void input()
{
	cin >> n >> k;
}

void solution()
{
	cout << (int) (k / pow(2, n - 1));
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