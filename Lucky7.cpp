#include <iostream>

using namespace std;

int n;
bool a, b;

void input()
{
	cin >> n;
}

void solution()
{
	if (!(n % 7))
		b = 1;

	while (n != 0)
	{
		if (n % 10 == 7)
			a = 1;

		n /= 10;
	}

	if (a == 0 && b == 0)
		cout << 0;

	else if (a == 0 && b == 1)
		cout << 1;

	else if (a == 1 && b == 0)
		cout << 2;

	else
		cout << 3;
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