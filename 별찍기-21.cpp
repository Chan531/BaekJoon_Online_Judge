#include <iostream>

using namespace std;

int n;

void odd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			if (j % 2)
			{
				for (int k = 1; k <= n; k++)
				{
					if (k % 2)
						cout << '*';
					else
						cout << ' ';
				}
			}
			else
			{
				for (int k = 1; k < n; k++)
				{
					if (k % 2)
						cout << ' ';
					else
						cout << '*';
				}
			}
			cout << '\n';
		}
	}
}

void even()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j % 2)
			{
				for (int k = 1; k <= n; k++)
				{
					if (k % 2)
						cout << ' ';
					else
						cout << '*';
				}
			}
			else
			{
				for (int k = 1; k < n; k++)
				{
					if (k % 2)
						cout << '*';
					else
						cout << ' ';
				}
			}
			cout << '\n';
		}
	}
}

void solve()
{
	cin >> n;
	if (n == 1)
		cout << '*';
	else if (n % 2)
		odd();
	else
		even();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}