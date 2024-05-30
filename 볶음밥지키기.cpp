#include <iostream>

using namespace std;

int n, r, x[101], y[101], ansx, ansy, ans;

void input()
{
	cin >> n >> r;

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
}

void solution()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			int cnt = 0;

			for (int k = 0; k < n; k++)
				if ((i - x[k]) * (i - x[k]) + (j - y[k]) * (j - y[k]) <= r * r)
					cnt++;

			if (ans < cnt)
			{
				ans = cnt;
				ansx = i;
				ansy = j;
			}
		}
	}

	cout << ansx << ' ' << ansy;
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