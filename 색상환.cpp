#include <iostream>
#define mod 1000000003

using namespace std;

int n, k;
long long dp[1001][1001];

void input()
{
	cin >> n >> k;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	// i��° ���� ĥ���� �ʴ´ٸ� dp[i - 1][j]
	// i��° ���� ĥ�Ѵٸ� dp[i - 2][j - 1]
	// i - 3�� �ƴ� i - 2�� ���� -> 1��°�� ĥ�� �� i��°�� ĥ�ϴ� ���� �ƴ� i - 1��°�� ĥ�Ѵٰ� ����
	// ���� : https://source-sc.tistory.com/5
	for (int i = 4; i <= n; i++)
		for (int j = 2; j <= k; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;

	cout << dp[n][k];
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