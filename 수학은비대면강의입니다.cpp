#include <iostream>

using namespace std;

int a, b, c, d, e, f;

void input()
{
	cin >> a >> b >> c >> d >> e >> f;
}

void solution()
{
	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			if ((a * i + b * j == c) && (d * i + e * j == f))
			{
				cout << i << ' ' << j;
				exit(0);
			}
		}
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