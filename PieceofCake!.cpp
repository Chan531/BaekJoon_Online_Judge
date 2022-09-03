#include <iostream>
#include <algorithm>

using namespace std;

int n, h, v;

void input()
{
	cin >> n >> h >> v;
}

void solution()
{
	cout << 4 * max(h, n - h) * max(v, n - v);
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