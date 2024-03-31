#include <iostream>

using namespace std;

int n, m, k;

void input()
{
	cin >> n >> m >> k;
}

void solution()
{
	cout << m / n * k;
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