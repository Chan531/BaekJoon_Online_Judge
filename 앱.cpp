#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	long long mem;
	int cost;
};

int n, m, ans = 10001;
long long dp[101][10000];             // i ��, j ���
node app[101];

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> app[i].mem;
	for (int i = 1; i <= n; i++)
		cin >> app[i].cost;
}

void solution()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (i == 0)     // �ƹ� �޸𸮵� ���� �� ����
			{
				dp[i][j] = 0;
				continue;
			}

			if (j >= app[i].cost)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - app[i].cost] + app[i].mem);     // i��° �۱��� ����� �� j�� ������� ���� �� �ִ� �ִ� �޸𸮷�

			else
				dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= m)
				ans = min(ans, j);
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
	cout.tie(NULL);

	solve();
	return 0;
}