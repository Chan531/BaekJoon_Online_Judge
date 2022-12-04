#include <iostream>

using namespace std;

int n, arr[10];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> arr[j];

		for (int j = 1; j <= 10; j++)
		{
			if (arr[j - 1] != (j - 1) % 5 + 1)
				break;

			if (j == 10)
				cout << i << '\n';
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