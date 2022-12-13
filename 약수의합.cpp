#include <iostream>
#define N 1000000

using namespace std;

int testcase, n;
long long sum[N + 1], ans;

void input()
{
	cin >> testcase;
}

void solution()
{
	sum[1] = 1;

	for (int i = 2; i <= N; i++)
		sum[i] = i + 1;

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = i * 2; j <= N; j += i)
		{
			sum[j] += i;

			if (j / i != i && j / i > 1000)
				sum[j] += j / i;
		}
	}

	for (int i = 2; i <= N; i++)
		sum[i] += sum[i - 1];

	while (testcase--)
	{
		cin >> n;
		cout << sum[n] << '\n';
	}
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