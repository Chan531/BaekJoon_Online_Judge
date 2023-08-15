#include <iostream>
#define N 202

using namespace std;

int n, m, ans, check[N][N];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		check[a][b] = 1;
		check[b][a] = 1;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (check[i][j])
				continue;

			for (int k = j + 1; k <= n; k++)
			{
				if (check[i][k] || check[j][k])
					continue;

				ans++;
			}
		}
	}

	cout << ans;
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