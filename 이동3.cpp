#include <iostream>
#include <cmath>

using namespace std;

int a, b, sum, ans, check[20];

void input()
{
	cin >> a >> b;
}

void solution()
{
	for (int i = 19; i >= 0; i--)
	{
		if (a >= pow(3, i))
		{
			a -= pow(3, i);
			check[i]++;
			sum++;
		}

		if (b >= pow(3, i))
		{
			b -= pow(3, i);
			check[i]++;
			sum++;
		}
	}

	if (a || b)
	{
		cout << ans;
		return;
	}

	for (int i = 0; i < 20; i++)
	{
		if (check[i] > 1)
			break;

		if (!check[i])
		{
			if (!sum)
				ans = 1;

			break;
		}

		sum--;
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

	solve();
	return 0;
}