#include <iostream>

using namespace std;

int x, y, z;

void input()
{
	cin >> x >> y >> z;
}

void solution()
{
	cout << ((x + y > z) ? 0 : 1);
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