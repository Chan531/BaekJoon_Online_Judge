#include <iostream>

using namespace std;

double a, b;

void input()
{

}

void solution()
{
	while (1)
	{
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			cout << "AXIS";
			return;
		}

		if (a == 0 || b == 0)
			cout << "AXIS\n";

		else if (a > 0 && b > 0)
			cout << "Q1\n";

		else if (a < 0 && b > 0)
			cout << "Q2\n";

		else if (a < 0 && b < 0)
			cout << "Q3\n";

		else
			cout << "Q4\n";
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