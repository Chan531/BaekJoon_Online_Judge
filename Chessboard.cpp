#include <iostream>

using namespace std;

int n, m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i % 2 == j % 2)
				cout << '*';

			else
				cout << '.';
		}

		cout << '\n';
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