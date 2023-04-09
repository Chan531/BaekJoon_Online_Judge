#include <iostream>

using namespace std;

int n, m, arr[101], arr_copy[101];

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		arr[i] = i;

	while (m--)
	{
		int i, j, k;
		cin >> i >> j >> k;

		int idx = i;

		for (int a = i; a <= j; a++)
			arr_copy[a] = arr[a];

		for (int a = k; a <= j; a++)
			arr[idx++] = arr_copy[a];

		for (int a = i; a < k; a++)
			arr[idx++] = arr_copy[a];
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
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