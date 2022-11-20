#include <iostream>
#include <cmath>
#define N 31623

using namespace std;

int n;
bool prime[N];

void set()
{
	prime[1] = 1;

	for (int i = 2; i <= N; i++)
		if (!prime[i])
			for (int j = i * 2; j <= N; j += i)
				prime[j] = 1;
}

void input()
{
	cin >> n;
}

void solution()
{
	int cnt = 1;

	for (int i = 2; i <= N; i++)
	{
		if (n % i == 0)
		{
			cnt *= (i - 1);
			n /= i;

			while (n % i == 0)
			{
				cnt *= i;
				n /= i;
			}
		}
	}

	n == 1 ? cout << cnt << '\n' : cout << cnt * (n - 1) << '\n';
}

void solve()
{
	while (1)
	{
		set();
		input();

		if (n == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}	