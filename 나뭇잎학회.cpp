#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	if (n == 1) cout << 0;
	else if (n % 2) cout << n * n / 2 + 1;
	else cout << n * n / 2;
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