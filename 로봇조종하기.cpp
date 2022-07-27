#include <iostream>
#include <algorithm>
#define N -1e9

using namespace std;

int n, m;
int map[1001][1001], dp[1001][1002][3];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
}

void solution()
{
	// ���η� map�� �ѷ��� ���� ����
	// N�� ������ �����Ͽ� �̵��� �������� �ʰ� �� (ex. map[a][1]�� ���������� �̵��ؼ� ������ �� ����)
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][0][j] = N;
			dp[i][m + 1][j] = N;
		}
	}	

	// ���� ������ ���������� �ۿ� �̵��� �� ����
	dp[1][0][0] = 0;

	for (int i = 1; i <= m; i++)
	{
		dp[1][i][0] = map[1][i] + dp[1][i - 1][0];
		dp[1][i][1] = N;
		dp[1][i][2] = N;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][2]) + map[i][j];
			dp[i][j][2] = max({ dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2] }) + map[i][j];
		}

		for (int j = m; j >= 1; j--)
			dp[i][j][1] = max(dp[i][j + 1][1], dp[i][j + 1][2]) + map[i][j];
	}

	cout << max({ dp[n][m][0],  dp[n][m][1], dp[n][m][2] });
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