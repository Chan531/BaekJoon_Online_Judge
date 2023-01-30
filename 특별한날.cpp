#include <iostream>

using namespace std;

int m, d;

void input()
{
	cin >> m >> d;
}

void solution()
{
	if (m > 2)
		cout << "After";

	else if (m == 2)
	{
		if (d > 18)
			cout << "After";

		else if (d == 18)
			cout << "Special";

		else
			cout << "Before";
	}

	else
		cout << "Before";
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