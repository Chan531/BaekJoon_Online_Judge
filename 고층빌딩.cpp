#include <iostream>
#define mod 1000000007

using namespace std;

int N, L, R;
long long dp[101][101][101];

void input()
{
	cin >> N >> L >> R;
}

void solution()
{
	dp[1][1][1] = 1;

	for (int i = 2; i <= N; i++)                   // �ǹ��� ����   
		for (int j = 1; j <= i; j++)               // ���ʿ��� ���̴� �ǹ��� ����
			for (int k = 1; k <= i; k++)           // �����ʿ��� ���̴� �ǹ��� ����
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % mod;
	            // dp[i][j][k]�� ������ ���� �ɰ� �� �ִ�.
	            // dp[i - 1][j - 1][k]���� ���� ���� �ǹ� �ϳ��� �� ���ʿ� �߰��ϸ� dp[i][j][k]�� �ȴ�.
	            // dp[i - 1][j][k - 1]���� ���� ���� �ǹ� �ϳ��� �� �����ʿ� �߰��ϸ� dp[i][j][k]�� �ȴ�.
	            // dp[i - 1][j][k]���� ���� ���� �ǹ��� ������ �ִ� �ǹ� ���̿� �߰��Ѵٸ� dp[i][j][k]�� �ȴ�. + �̷��� ��찡 (i - 2)���� �ִ�.

	cout << dp[N][L][R];
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