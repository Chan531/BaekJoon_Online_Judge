#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;

		if (m == 300)
			cout << "1 ";

		else if (m >= 275)
			cout << "2 ";

		else if (m >= 250)
			cout << "3 ";

		else
			cout << "4 ";
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