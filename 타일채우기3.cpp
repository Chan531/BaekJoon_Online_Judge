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

	// 3��°���� ���� 2 * 1�� 1 * 1�� �̷���� ���ο� ���°� 2���� ������ (+ 2)
	// �׷��Ƿ� i - 3��°������ ��� ����� ���� 2�� ������ ���� ������� �� (sum * 2)
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