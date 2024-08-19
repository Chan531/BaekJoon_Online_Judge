#include <iostream>
#include <algorithm>

using namespace std;

int arr[4], ans[6][4] = { {0, 1, 2, 3}, {1, 3, 5, 7}, {0, 2, 4, 6}, {0, 1, 4, 5}, {4, 5, 6, 7}, {2, 3, 6, 7} };

void input()
{
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + 4);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] != ans[i][j]) break;
			if (j == 3)
			{
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}