#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, c;

void input()
{
	cin >> n >> a >> b >> c;
}

void solution()
{
	cout << min(a, n) + min(b, n) + min(c, n);
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