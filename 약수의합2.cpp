#include <iostream>
#include <cmath>

using namespace std;

int n;
long long ans;

void input()
{
	cin >> n;
}

void solution()
{
	// 10까지 세보면 1이 10개, 2가 5개, 3이 3개... 10이 1개.
	for (int i = 1; i <= n; i++)
		ans += (n / i) * i;

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

/*
#include <iostream>
#include <cmath>

using namespace std;

int n;
long long sum[1000001], ans;

void input()
{
	cin >> n;
}

void solution()
{
	sum[1] = 1;

	for (int i = 2; i <= n; i++)
		sum[i] += i + 1;

	for (int i = 2; i <= sqrt(n); i++)
	{
		for (int j = i * 2; j <= n; j += i)
		{
			sum[j] += i;

			if (j / i != i && j / i > sqrt(n))
				sum[j] += j / i;
		}
	}

	for (int i = 1; i <= n; i++)
		ans += sum[i];

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
*/