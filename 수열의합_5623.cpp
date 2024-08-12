#include <iostream>
#define N 1010

using namespace std;

int n, arr[N][N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
}

void solution()
{
	if (n == 2)
	{
		cout << arr[1][2] / 2 << ' ';

		if (arr[1][2] % 2)
			cout << arr[1][2] / 2 + 1;
		else
			cout << arr[1][2] / 2;
		return;
	}

	cout << (arr[1][2] + arr[1][3] - arr[2][3]) / 2 << ' ';

	for (int i = 2; i < n; i++)
		cout << (arr[i][i - 1] + arr[i][i + 1] - arr[i + 1][i - 1]) / 2 << ' ';

	cout << (arr[n][n - 1] + arr[n][n - 2] - arr[n - 1][n - 2]) / 2;
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