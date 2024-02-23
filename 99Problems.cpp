#include <iostream>

using namespace std;

int n, m;

void input()
{
	cin >> n;
}

void solution()
{
	while (++m)
	{
		if ((n + m) % 100 == 99)
		{
			cout << n + m;
			break;
		}

		if ((n - m) % 100 == 99)
		{
			cout << n - m;
			break;
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