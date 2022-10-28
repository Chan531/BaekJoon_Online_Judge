#include <iostream>

using namespace std;

int n, a, b, c, d;

void input()
{
	cin >> a >> b >> n;
}

void solution()
{
	a = a % b;

	while (n--)
	{
		c = a * 10 / b;
		d = a * 10 % b;
		a = d;
	}

	cout << c;
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