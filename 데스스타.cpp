#include <iostream>
#include <cstring>
#define N 1010
#define K 30

using namespace std;

int n, arr[N][N], ans[N];
bool check[K];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			for (int k = 0; k < K; k++)
			{
				if (arr[i][j] < (1 << k))
					break;

				if (check[k])
					continue;

				if (arr[i][j] & (1 << k))
				{
					ans[i] += (1 << k);
					check[k] = 1;
				}
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			for (int k = 0; k < K; k++)
			{
				if (arr[j][i] < (1 << k))
					break;

				if (check[k])
					continue;

				if (arr[j][i] & (1 << k))
				{
					ans[i] += (1 << k);
					check[k] = 1;
				}
			}
		}

		memset(check, 0, sizeof(check));
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
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