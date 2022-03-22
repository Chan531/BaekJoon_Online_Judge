#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, list[101][101];

void input()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		list[a][b] = 1;
		list[b][a] = -1;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)                      // j와 k 비교를 위한 매개체
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (list[j][i] == 1 && list[i][k] == 1)     // j > i > k라면
					list[j][k] = 1;
				if (list[j][i] == -1 && list[i][k] == -1)   // j < i < k라면
					list[j][k] = -1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (list[i][j] == 0)
				cnt++;
		}
		cout << cnt - 1 << '\n';
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