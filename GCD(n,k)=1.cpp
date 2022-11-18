#include <iostream>

using namespace std;

long long n;

void input()
{
	cin >> n;
}

void solution()
{
	long long ans = 1;

	while (1)
	{
		for (long long p = 2; p <= 1000000; p++)
		{
			if (n % p == 0)
			{
				// 소수 p의 오일러 피 함수 값 = p - 1
				ans *= (p - 1);
				n /= p;

				// 소수 p의 거듭제곱 p^k의 오일러 피 함수 값 = p^(k - 1) * (p - 1)
				while (n % p == 0)
				{
					ans *= p;
					n /= p;
				}
			}
		}

		if (n == 1)
			break;

		// 10^6보다 큰 소수가 남을 수 있음
		else
		{
			ans *= (n - 1);
			break;
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