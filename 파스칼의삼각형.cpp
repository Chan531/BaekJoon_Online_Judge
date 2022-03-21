#include <iostream>

using namespace std;

int n, k, arr[30][31];

void input()
{
	cin >> n >> k;
}

void solution()
{
	arr[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
				continue;
			}

			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	cout << arr[n - 1][k - 1];
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