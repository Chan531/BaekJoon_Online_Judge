#include <iostream>
#define N 5000050

using namespace std;

int n, b, s;
bool cur, check[N];

void input()
{
	cin >> n;
}

void init()
{
	check[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (check[i])
			continue;

		for (int j = i * 2; j <= n; j += i)
			check[j] = 1;
	}
}

void solution()
{
	init();

	for (int i = 1; i <= n; i++)
	{
		if (check[i])
		{
			b++;
			cur = 1;
		}

		else
		{
			if (cur)
			{
				s += 2;
				b--;
				cur = 0;
			}

			else
				s++;
		}
	}

	cout << b << ' ' << s;
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