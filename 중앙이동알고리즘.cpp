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
	cout << (long long) pow((pow(2, n) + 1), 2);
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