#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	if (a == b + c)
		cout << a << '=' << b << '+' << c;

	else if (a == b - c)
		cout << a << '=' << b << '-' << c;

	else if (a == b * c)
		cout << a << '=' << b << '*' << c;

	else if (a == b / c && b % c == 0)
		cout << a << '=' << b << '/' << c;

	else if (a + b == c)
		cout << a << '+' << b << '=' << c;

	else if (a - b == c)
		cout << a << '-' << b << '=' << c;

	else if (a * b == c)
		cout << a << '*' << b << '=' << c;

	else if (a / b == c && a % b == 0)
		cout << a << '/' << b << '=' << c;

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