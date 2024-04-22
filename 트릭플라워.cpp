#include <iostream>
#define N 1010

using namespace std;

int a, b, r;
bool check[N][N];

void input()
{
	cin >> a >> b >> r;
}

void solution()
{
	for (int i = 0; ; i++)
	{
		if (check[a][b])
		{
			cout << i;
			break;
		}

		check[a][b] = 1;

		if (a + b + 2 < r)
		{
			a++;
			b++;
		}

		else
		{
			a /= 2;
			b /= 2;
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

	solve();
	return 0;
}