#include <iostream>

using namespace std;

string map[10][10];

void input()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (map[i][j] != map[i][j - 1])
				break;

			if (j == 9)
			{
				cout << 1;
				return;
			}
		}

		for (int j = 1; j < 10; j++)
		{
			if (map[j][i] != map[j - 1][i])
				break;

			if (j == 9)
			{
				cout << 1;
				return;
			}
		}
	}

	cout << 0;
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