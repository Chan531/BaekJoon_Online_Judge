#include <iostream>

using namespace std;

int a, b, c, d, ans;

void input()
{
	cin >> a >> b >> c >> d;
}

void solution()
{
	int cur = 0;

	for (int i = 0; i <= d / a; i++)
	{
		cur += a * i;
		for (int j = 0; j <= d / b; j++)
		{
			cur += b * j;
			for (int k = 0; k <= d / c; k++)
			{
				cur += c * k;
				if (cur == d) ans = 1;
				cur -= c * k;
			}
			cur -= b * j;
		}
		cur -= a * i;
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