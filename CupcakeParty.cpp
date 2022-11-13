#include <iostream>

using namespace std;

int r, s;

void input()
{
	cin >> r >> s;
}

void solution()
{
	cout << 8 * r + 3 * s - 28;
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