#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	int c = gcd(a, b);

	for (int i = 1; i <= c; i++)
		if (c % i == 0)
			cout << i << ' ' << a / i << ' ' << b / i << '\n';
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