#include <iostream>
#define mod 1000000007

using namespace std;

int n, k;
long long ans = 1;

void input()
{
	cin >> n >> k;
}

long long mul(long long a, int b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a % mod;

	if (b % 2)
	{
		long long c = mul(a, b - 1);
		return c * a % mod;
	}

	else
	{
		long long c = mul(a, b / 2);
		return c * c % mod;
	}
}

void solution()
{
	long long m = 1;

	// �丣���� ������
	// p�� �Ҽ��̰� a�� p�� ����� �ƴ϶�� a^(p - 1) == 1 (mod p)�� �����Ѵ�.
	// a^(p - 1)�� p�� ���� �������� 1�̶�� ���̴�.
	// �� ���� a^(p - 2)�� ���� �شٸ�
	// a^-1 % p == a^(p - 2) % p�� ����
	// �����־���ϴ� k!�� ��������ϴ� k!^(p - 2)�� �ȴ�.

	// n! / (n - k)!
	for (int i = n; i > n - k; i--)
	{
		ans *= i;
		ans %= mod;
	}

	// k!
	for (int i = 1; i <= k; i++)
	{
		m *= i;
		m %= mod;
	}

	cout << ans * mul(m, mod - 2) % mod;
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