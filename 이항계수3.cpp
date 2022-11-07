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

	// 페르마의 소정리
	// p가 소수이고 a가 p의 배수가 아니라면 a^(p - 1) == 1 (mod p)가 성립한다.
	// a^(p - 1)를 p로 나눈 나머지는 1이라는 뜻이다.
	// 양 변을 a^(p - 2)로 나눠 준다면
	// a^-1 % p == a^(p - 2) % p가 성립
	// 나눠주어야하는 k!가 곱해줘야하는 k!^(p - 2)가 된다.

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