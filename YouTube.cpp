#include <iostream>
#define N 100001
#define K 30

using namespace std;

int n, k, m, arr[N], sparse_table[K][N], dp[N];

void input()
{
	cin >> n >> k >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i <= k; i++)
		cin >> sparse_table[0][i];
}

void set_sparse_table()
{
	for (int i = 1; i < K; i++)
		for (int j = 1; j <= k; j++)
			sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];
}

void solution()
{
	set_sparse_table();

	for (int i = 0; i < n; i++)
	{
		if (dp[arr[i]] == 0)
		{
			int a = arr[i];

			for (int i = 0; i < K; i++)
				if ((1 << i) & (m - 1))
					a = sparse_table[i][a];

			dp[arr[i]] = a;
		}

		cout << dp[arr[i]] << ' ';
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