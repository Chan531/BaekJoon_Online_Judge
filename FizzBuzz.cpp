#include <iostream>

using namespace std;

int a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void solution()
{
	for (int i = 1; i <= c; i++)
	{
		if (i % a == 0 && i % b == 0)
			cout << "FizzBuzz\n";

		else if (i % a == 0)
			cout << "Fizz\n";

		else if (i % b == 0)
			cout << "Buzz\n";

		else
			cout << i << '\n';
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