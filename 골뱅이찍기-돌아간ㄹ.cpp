#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 5 * n; i++)
	{
		if (i <= n)
		{
			for (int j = 0; j < 3 * n; j++)
				cout << '@';

			for (int j = 0; j <  n; j++)
				cout << ' ';

			for (int j = 0; j < n; j++)
				cout << '@';

			cout << '\n';
			continue;
		}

		if (i > 4 * n)
		{
			for (int j = 0; j < n; j++)
				cout << '@';

			for (int j = 0; j < n; j++)
				cout << ' ';

			for (int j = 0; j < 3 * n; j++)
				cout << '@';

			cout << '\n';
			continue;
		}

		for (int j = 0; j < n; j++)
			cout << '@';

		for (int j = 0; j < n; j++)
			cout << ' ';

		for (int j = 0; j < n; j++)
			cout << '@';

		for (int j = 0; j < n; j++)
			cout << ' ';

		for (int j = 0; j < n; j++)
			cout << '@';

		cout << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}