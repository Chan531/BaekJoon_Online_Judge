#include <iostream>

using namespace std;

int n, m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	if (n - 7 >= 1)
		cout << n - 7;

	else
		cout << m + 7;
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