#include <iostream>

using namespace std;

long long n, k;

void input()
{
	cin >> n >> k;
}

void solution()
{
	cout << n * n * k;
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