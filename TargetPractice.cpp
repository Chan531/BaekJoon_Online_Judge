#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void out()
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n - 1)
			cout << '|';

		else
			cout << '-';
	}

	cout << '\n';
}

void in(int i)
{
	for (int j = 0; j < n; j++)
	{
		if (j == 0 || j == n - 1)
			cout << '|';

		else
		{
			if (i == j || n - 1 - i == j)
				cout << '*';

			else
				cout << ' ';
		}
	}

	cout << '\n';
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n - 1)
			out();

		else		
			in(i);
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
	cout.tie(NULL);

	solve();
	return 0;
}