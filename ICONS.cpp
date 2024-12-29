#include <iostream>

using namespace std;

int n, val = 22, y, x;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (i * j >= n && val > i + j)
			{
				y = i;
				x = j;
				val = i + j;
			}
		}
	}

	cout << y << ' ' << x;
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