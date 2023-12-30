#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d, e;

void input()
{
	cin >> a >> b >> c >> d >> e;
}

void solution()
{
	cout << a + 21 * max(0, e - 30) * b << ' ' << c + 21 * max(0, e - 45) * d;
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