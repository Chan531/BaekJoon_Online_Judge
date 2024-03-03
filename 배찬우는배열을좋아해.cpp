#include <iostream>
#include <algorithm>
#define N 3030

using namespace std;

int n, m, q, map[N][N], arr[N];

void input()
{
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < n; i++)
		arr[i] = i;

	while (q--)
	{
		int c, i, j;
		cin >> c >> i >> j;

		if (c == 0)
			cin >> map[arr[i]][j];

		else
			swap(arr[i], arr[j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << map[arr[i]][j] << ' ';

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

	solve();
	return 0;
}