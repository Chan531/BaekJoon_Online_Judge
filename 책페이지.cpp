#include <iostream>

using namespace std;

int n, m, cnt, arr[10];

void input()
{
	cin >> n;
}

void cal(int a)
{
	while (a)
	{
		arr[a % 10] += cnt;
		a /= 10;
	}
}

void solution()
{
	cnt = 1;

	while (n)
	{
		m = 1;

		while (m % 10 != 0 && m <= n)
		{
			cal(m);
			m++;
		}

		if (!(n / 10))
			break;

		while (n % 10 != 9 && n >= m)
		{
			cal(n);
			n--;
		}

		for (int i = 0; i < 10; i++)
			arr[i] += n / 10 * cnt;

		cnt *= 10;
		n /= 10;
	}

	for (auto i : arr)
		cout << i << ' ';
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