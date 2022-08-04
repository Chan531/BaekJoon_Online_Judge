#include <iostream>
#define mod 1000000007

using namespace std;

int n;
long long sum;

void input()
{
	cin >> n;
}

void solution()
{
	long long dp1 = 2, dp2 = 7;

	if (n == 1)
	{
		cout << dp1;
		return;
	}

	if (n == 2)
	{
		cout << dp2;
		return;
	}

	// 3번째부터 끝이 2 * 1과 1 * 1로 이루어진 새로운 형태가 2개씩 등장함 (+ 2)
	// 그러므로 i - 3번째까지의 모든 경우의 수에 2를 곱해준 값을 더해줘야 함 (sum * 2)
	for (int i = 3; i <= n; i++)
	{
		long long temp = dp2;
		dp2 = (dp2 * 2 + dp1 * 3 + sum * 2 + 2) % mod;
		sum += dp1;
		dp1 = temp;
		sum %= mod;
	}

	cout << dp2;
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