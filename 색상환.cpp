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

	// i번째 색을 칠하지 않는다면 dp[i - 1][j]
	// i번째 색을 칠한다면 dp[i - 2][j - 1]
	// i - 3이 아닌 i - 2인 이유 -> 1번째를 칠할 때 i번째를 칠하는 것이 아닌 i - 1번째를 칠한다고 생각
	// 참고 : https://source-sc.tistory.com/5
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