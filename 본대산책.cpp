#include <iostream>
#include <vector>

using namespace std;

int n;
long long dp[101010][8], mod = 1000000007;
vector<int> con[8];

/* 
�������а�: 0
����� : 1
�̷��� : 2
�ž�� : 3
�Ѱ������� : 4
������ : 5
�л�ȸ�� : 6
�������а� : 7
*/

void input()
{
	cin >> n;
}

void init()
{
	con[0] = { 1, 2 };
	con[1] = { 0, 2, 3 };
	con[2] = { 0, 1, 3, 4 };
	con[3] = { 1, 2, 4, 5 };
	con[4] = { 2, 3, 5, 7 };
	con[5] = { 3, 4, 6 };
	con[6] = { 5, 7 };
	con[7] = { 4, 6 };
	dp[0][0] = 1;
}

void solution()
{
	init();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < con[j].size(); k++)
			{
				dp[i][j] += dp[i - 1][con[j][k]];
				dp[i][j] %= mod;
			}
		}
	}

	cout << dp[n][0];
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