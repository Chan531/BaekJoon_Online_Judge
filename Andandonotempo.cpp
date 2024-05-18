#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	if (a == b || b == c || a == c)
		cout << 'S';

	else if (a + b == c || a + c == b || b + c == a)
		cout << 'S';

	else
		cout << 'N';
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