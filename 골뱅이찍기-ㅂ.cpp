#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == 1 || i == 3)
			{
				for (int k = 0; k < n * 5; k++)
				{
					if (k < n || k >= 4 * n)
						cout << '@';

					else
						cout << ' ';
				}
			}

			else
			{
				for (int k = 0; k < n * 5; k++)
					cout << '@';
			}

			cout << '\n';
		}
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