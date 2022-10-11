#include <iostream>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		// 짝수 개수로 나누어질 때
		if (i % 2)
		{
			if (n % i)
				continue;
			
			if (n / i - i / 2 < 1)
				break;
		}

		// 홀수 개수로 나누어질 때
		else
		{
			if (n % i != i / 2)
				continue;

			if (n / i - i / 2 < 0)
				break;
		}

		ans++;
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