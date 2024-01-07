#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	// a를 min으로 만들어줌
	if (a > b)
		swap(a, b);

	if (b - a > c)
		cout << (a + c) * 2;

	else
	{
		c -= (b - a);
		a = b;
		a += c / 2;
		cout << 2 * a;
	}
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