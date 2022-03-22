#include <iostream>

using namespace std;

int n, m, a, b, comp[501][501], cnt = 0;

void input()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		comp[b][a] = 1;
		comp[a][b] = -1;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (comp[j][i] == 1 && comp[i][k] == 1)    // j > i > k
					comp[j][k] = 1;

				if (comp[j][i] == -1 && comp[i][k] == -1)  // j < i < k
					comp[j][k] = -1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				if (j == n)
					cnt++;

				continue;
			}

			if (!comp[i][j])
				break;

			if (j == n)
				cnt++;
		}
	}
	cout << cnt;
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