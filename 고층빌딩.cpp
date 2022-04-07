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

	for (int i = 2; i <= N; i++)                   // 건물의 개수   
		for (int j = 1; j <= i; j++)               // 왼쪽에서 보이는 건물의 개수
			for (int k = 1; k <= i; k++)           // 오른쪽에서 보이는 건물의 개수
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % mod;
	            // dp[i][j][k]는 다음과 같이 쪼갤 수 있다.
	            // dp[i - 1][j - 1][k]에서 가장 작은 건물 하나를 맨 왼쪽에 추가하면 dp[i][j][k]가 된다.
	            // dp[i - 1][j][k - 1]에서 가장 작은 건물 하나를 맨 오른쪽에 추가하면 dp[i][j][k]가 된다.
	            // dp[i - 1][j][k]에서 가장 작은 건물을 기존에 있는 건물 사이에 추가한다면 dp[i][j][k]가 된다. + 이러한 경우가 (i - 2)개가 있다.

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